include ../../rules.mk
include ../defines.mk

SOURCES    = $(wildcard *.cpp) 
OBJECTS    = $(SOURCES:.cpp=.o)

EXE := test-runner

all debug profile: $(EXE)

libpbihdf_gtest.a: $(OBJECTS)
	$(AR) $(ARFLAGS)c $@ $^

$(EXE): $(OBJECTS)
	$(CXX) $(CXXOPTS) $(CXXFLAGS) $^ $(GTEST_SRC) -o $@ -I$(GTEST_ROOT) $(LIBDIRS) $(LDFLAGS)

$(OBJECTS): %.o: %.cpp
	$(CXX) $(CXXOPTS) $(CXXFLAGS) -c $< -o $@ $(INCDIRS)

gtest: $(EXE)
	./$< --gtest_output=xml:../xml/hdf.xml

clean:
	@find . -type f -name \*.o -delete
	@find . -type f -name \*.d -delete
	@rm -f libpbihdf_gtest.a $(EXE) ../xml/hdf.xml
