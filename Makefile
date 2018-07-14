#PROJECT : C-Template -- Main Makefile

#######################################################
###				CONFIGURATION
#######################################################

SRC_DIR = src
TST_DIR = tst
INS_DIR = install

CC			= gcc
CFLAGS		= -Wall -Wextra -std=c99 -g -O0
CPPFLAGS	= -I ${SRC_DIR} -I ${TST_DIR}
LFFLAGS		=
SRVFLAGS	=

MAIN_SRC	= $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/common/*.c)
MAIN_OBJ	= $(MAIN_SRC:%.c=%.o)
MAIN_EXEC	= main


#######################################################
###				COMMANDS CATEGORIES
#######################################################

# Accessible commands
.PHONY: all help build install run vrun test vtest ctest docs clean

# Helper commands
.PHONY: --prebuild

#######################################################
###				DEFAULT MAKE COMMAND
#######################################################

all: build


#######################################################
###				MAKE INSTRUCTIONS / HELP
#######################################################

help:
	@echo -e \
	======================================================================	'\n'\
		'\t' C-Template \(2018\) by Bokoblin								'\n'\
	======================================================================	'\n'\
	'\n'Available commands:													'\n'\
		'\t' make help		'\t' Show the availables commands				'\n'\
		'\t' make build		'\t' Build the server and clients				'\n'\
		'\t' make install	'\t' Install the binairies						'\n'\
		'\t' make run		'\t' Run the server with the clients			'\n'\
		'\t' make vrun		'\t' Run with memory check 						'\n'\
		'\t' make test		'\t' Execute all the tests						'\n'\
		'\t' make vtest		'\t' Execute all the tests with memory check 	'\n'\
		'\t' make ctest		'\t' Execute all the tests with a coverage		'\n'\
		'\t' make docs		'\t' Generate the documentation					'\n'\
		'\t' make clean 	'\t' Clean all generated objects and binairies	'\n'


#######################################################
###				MAKE BUILD
#######################################################

--prebuild:
	@echo Starting building...

build: --prebuild $(MAIN_EXEC)
	@echo Building complete.

$(MAIN_EXEC): $(MAIN_OBJ)
	$(CC) $^ -o $@


#######################################################
###				MAKE INSTALL
#######################################################

install: build
	@echo
	@echo Starting installation...
	@mkdir -p install
	@echo Installation directory: "${PWD}/$(INS_DIR)"
	@mv $(MAIN_EXEC) $(INS_DIR)
	@find . -type f -name '*.o' -delete
	@echo Installation complete.


#######################################################
###				MAKE RUN
#######################################################

run:
	@echo Running program...
	@./$(INS_DIR)/$(MAIN_EXEC)


#######################################################
###				MAKE RUN WITH VALGRING
#######################################################

vrun:
	@echo Running program with valgrind...
	@valgrind ./$(INS_DIR)/$(MAIN_EXEC)


#######################################################
###				MAKE TEST
#######################################################

test: 
	@echo Starting the tests
	@$(MAKE) --no-print-directory -C $(TST_DIR) test


#######################################################
###				MAKE TEST WITH VALGRIND
#######################################################

vtest: 
	@echo Starting the tests with memory check
	@$(MAKE) --no-print-directory -C $(TST_DIR) vtest


#######################################################
###				MAKE TEST WITH COVERAGE
#######################################################

ctest: 
	@echo Starting the tests with coverage
	@$(MAKE) --no-print-directory -C $(TST_DIR) ctest


#######################################################
###				MAKE DOCUMENTATION
#######################################################

docs:
	doxygen Doxyfile


#######################################################
###				MAKE CLEAN
#######################################################

clean:
	@echo Starting cleanup...
	@find . -type f -name '*.o' -delete
	@find . -type f -name '*.so' -delete
	@rm -rf $(INS_DIR)/*
	@$(MAKE) --no-print-directory -C $(TST_DIR) clean
	@echo Cleanup complete.


#######################################################
###				OBJECTS FILES
#######################################################

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
