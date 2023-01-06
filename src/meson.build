hadron_sources = [
  'main.c',
  'hadron-application.c',
  'hadron-window.c',
]

hadron_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
]

hadron_sources += gnome.compile_resources('hadron-resources',
  'hadron.gresource.xml',
  c_name: 'hadron'
)

executable('hadron', hadron_sources,
  dependencies: hadron_deps,
       install: true,
)
