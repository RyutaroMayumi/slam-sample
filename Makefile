# Makefile Template.

# .
# |-- Makefile (This file)
# |-- build
# |   `-- target file.
#     |-- obj
#         `-- object files.
# |-- include
# |   `-- header files.
# `-- source
#     `-- source files.

# Variables
## Directory defines
BUILDDIR = ./build
OBJDIR = $(BUILDDIR)/obj
SRCDIR = ./source
FLTOUT = #./3rdparty/	# register main.cpp files ignored from build target
INCDIRS = ./include #./3rdparty/
LIBDIRS = #-L

## Target name
TARGET = $(BUILDDIR)/a.out

## Compiler options
CC = gcc
CFLAGS = -O2 -Wall
CXX = g++
CXXFLAGS = -O2 -Wall
LDFLAGS =

SRCS := $(shell find $(SRCDIR) -name *.cpp -or -name *.c -or -name *.s)
SRCS := $(filter-out $(FLTOUT), $(SRCS))
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)
LIBS = #-lboost_system -lboost_thread

INCLUDE := $(shell find $(INCDIRS) -type d)
INCLUDE := $(addprefix -I,$(INCLUDE))

CPPFLAGS := $(INCLUDE) -MMD -MP
LDFLAGS += $(LIBDIRS) $(LIBS)

# Target
default:
	make all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# assembly
$(OBJDIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(OBJDIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(OBJDIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean rebuild debug prof

clean:
	$(RM) -r $(BUILDDIR)

rebuild:
	make clean && make

debug: CFLAGS = -O0 -Wall -g3	# Optimization OFF, Debug information ON
debug: CXXFLAGS = -O0 -Wall -g3	# Optimization OFF, Debug information ON
debug: all

prof: CFLAGS = -O2 -Wall -pg	# Optimization ON, Profiling ON
prof: CXXFLAGS = -O2 -Wall -pg	# Optimization ON, Profiling ON
prof: LDFLAGS += -pg			# Profiling ON
prof: all

-include $(DEPS)

MKDIR_P = mkdir -p
