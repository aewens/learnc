CFLAGS=-Wall -g

# all: origin
# 
# origin: object.o

clean:
	find . -maxdepth 1 -type f -perm +111 -print -exec rm -rf {} \;
	find . -maxdepth 1 -name "*.dSYM" -exec rm -rf {} \;
	clear;
