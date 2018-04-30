# Defining object files
OBJ = main.o display.o makeFigure.o

# Defining dependencies
DEPS = output.h

# Defining the application 
APPNAME = figures.a

# Link rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm

# Compiling rule
%.o : %.c $(DEPS)
	gcc -c -o $@ $<

# Cleaning rule
clean : 
	rm $(OBJ) $(APPNAME)