
PROJECTS = monotonic concat set linear_system


.PHONY: all clean

all: $(addsuffix _build, $(PROJECTS))

clean: $(addsuffix _clean, $(PROJECTS))

%_build:
	cd $(@:_build=) && $(MAKE)
	
%_clean:
	cd $(@:_clean=) && $(MAKE) clean

