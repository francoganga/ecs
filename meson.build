project('my_cpp_project', 'cpp')

# Set the C++ standard
cpp_std = 'c++17'

# Define your source files
src_files = [
  'main.cpp',
  'file1.cpp',
  'file2.cpp',
  # Add more source files here as needed
]

# Add include directories if necessary
inc_dirs = include_directories('include')

# Define your executable
executable('my_cpp_executable', src_files,
           include_directories: inc_dirs,
           cpp_std: cpp_std)
