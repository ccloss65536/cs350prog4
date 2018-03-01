#Carl Closs, Timothy Shores
NUM = 4
HEADERS = 
COMPILE = g++
FLAGS = -g -Wall -Wextra -Wno-unused-parameter -lrt
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
$(NAME1): $(NAME1).c 
	$(COMPILE) -c $(FLAGS) $(NAME1).cpp 
	$(COMPILE) $(FLAGS) $(NAME1).o -o $(NAME1)
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
		mutt -s "CA$(NUM)_submission" ccloss1@binghamton.edu <submit.htm -a ../$(FILE)
endif
	#hack to determine whether we should use firefox or email to self
