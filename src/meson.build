hadron_sources = [
  'main.c',
  'hadron-application.c',
  'hadron-window.c',
]

hadron_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
]

blueprints = custom_target('blueprints',
  input: files(
    'gtk/help-overlay.blp',
    'hadron-window.blp',
  ),
  output: '.',
  command: [find_program('blueprint-compiler'), 'batch-compile', '@OUTPUT@', '@CURRENT_SOURCE_DIR@', '@INPUT@'],
)


hadron_sources += gnome.compile_resources('hadron-resources',
  'hadron.gresource.xml',
  c_name: 'hadron',
  dependencies: blueprints,
)

executable('hadron', hadron_sources,
  dependencies: hadron_deps,
       install: true,
)
