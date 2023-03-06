project('hadron', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

subproject('imgui')

exe = executable('hadron', 'hadron.cpp',
  install : true,
  dependencies: [
    dependency('imgui'),
    dependency('gl'),
    dependency('glfw3'),
  ])

test('basic', exe)
