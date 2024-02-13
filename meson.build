project('my_cpp_project', 'cpp')


# Define your source files
src_files = [
  'src/main.cpp',
  'src/game.cpp',
  'src/entity_manager.cpp',
  'src/entity.cpp',
  'src/vec2.cpp',
]

imgui_src = [
  'lib/imgui/imgui.cpp',
  'lib/imgui/imgui_demo.cpp',
  'lib/imgui/imgui_draw.cpp',
  'lib/imgui/imgui_tables.cpp',
  'lib/imgui/imgui_widgets.cpp',
]

imgui_sfml_src = [
  'lib/imgui-sfml/imgui-SFML.cpp'
]

# Add include directories if necessary
inc_dirs = include_directories('lib/imgui-sfml', 'lib/imgui')

libs = [dependency('sfml-graphics'), dependency('sfml-window'), dependency('sfml-system'), dependency('GL')]  # SFML libraries

imgui_lib = static_library('imgui', imgui_src)
imgui_sfml_lib = static_library('imgui_sfml', imgui_sfml_src,
                                include_directories: ['lib/imgui'],
                                link_with: imgui_lib,
                                dependencies: libs)

imgui_dep = declare_dependency(link_with: imgui_lib, include_directories: inc_dirs)
imgui_sfml_dep = declare_dependency(link_with: imgui_sfml_lib, include_directories: inc_dirs)

deps = [dependency('sfml-graphics'), dependency('sfml-window'), dependency('sfml-system'), dependency('GL'), imgui_dep, imgui_sfml_dep]

executable('game', src_files,
  include_directories: inc_dirs, dependencies: deps)
