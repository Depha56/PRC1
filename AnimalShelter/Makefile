
PN=animal_shelter
CFLAGS=-Wall -Werror -Iproduct -I../Unity -Itest

#add your own other c files here
SHARED=	product/administration.c \
        product/file_element.c 
	                         
TEST=$(SHARED) \
             test/Unity/unity.c 

SHAREDTEST=  test/administration_test.c 

gcc=$(CC)
all: 
	$(CC) $(CFLAGS) product/$(PN).c $(SHARED) -o $(PN) 

adminTest:
	$(CC) $(CFLAGS) $(SHAREDTEST) $(TEST) -o administrationTest 

clean:
	rm -rf administrationTest $(PN) 

