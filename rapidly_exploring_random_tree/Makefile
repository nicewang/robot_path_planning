# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
INCDIR = include
SRCDIR = src
OBJDIR = obj

# Files
SRCFILES = $(SRCDIR)/rrt.cpp $(SRCDIR)/main.cpp
OBJFILES = $(OBJDIR)/rrt.o $(OBJDIR)/main.o
TARGET = rrt.so

# Ensure the object directory exists and compile target
$(TARGET): $(OBJFILES)
	$(CXX) $(OBJFILES) -o $(TARGET)

# Create object directory if not exists and compile source files into objects
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean up
clean:
	rm -rf $(OBJDIR) $(TARGET)
