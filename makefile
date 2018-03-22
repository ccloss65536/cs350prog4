#Carl Closs, Timothy Shores
SHELL := /bin/bash
NUM = 4
HEADERS = workloads.hpp policies.hpp
COMPILE = g++
FLAGS = -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -O3 -lrt 
NAME1 = prog$(NUM)pagepolicy
NAME2 = nil
FILE =  Prog$(NUM)Closs_ccloss1.tar.gz
TESTOPTS = lol
DEBUG_OPTS = --silent -x cmds.txt
all: $(NAME1)
debug: $(NAME1)
	gdb $(DEBUG_OPTS)
common: common.c
	$(COMPILE) -c common.c $(FLAGS)
time: 
	$(COMPILE) -c $(FLAGS)
push:
	#@read -p "commit message (input ctrl+C to stop the push process, 1 line only): " MESSAGE
	git add -A
	git commit #-m "$(MESSAGE)"
	git push 
	@#Only in bash, read can have a prompt,
	@#and put the entire imput string into an enviroment variable called $REPLY
$(NAME1): $(NAME1).cpp policies.cpp workloads.cpp 
	$(COMPILE) -c $(FLAGS) *.cpp
	$(COMPILE) $(FLAGS) $(NAME1).o policies.o workloads.o -o $(NAME1)
$(NAME2): $(NAME2).cpp
	$(COMPILE) -c $(FLAGS) $(NAME2).c
	$(COMPILE) $(FLAGS) $(NAME2).o -o $(NAME2)
clean:
	rm -f *.o *.swp *.gch .go* $(NAME1) .nfs*
submit: $(NAME1) clean
	cd .. && 	tar -cvzf  $(FILE) Prog$(NUM)Closs_ccloss1
ifneq "$(findstring remote, $(HOSTNAME))"  "remote"
		firefox submit.htm
else 
		mutt -s "Prog$(NUM)_submission" ccloss1@binghamton.edu <submit.htm -a ../$(FILE)
endif
	#hack to determine whether we should use firefox or email to self
