hadron_sources = [
  'main.vala',
  'application.vala',
  'window.vala',
]

hadron_deps = [
  dependency('gtk4'),
]

hadron_sources += gnome.compile_resources('hadron-resources',
  'hadron.gresource.xml',
  c_name: 'hadron'
)

executable('hadron', hadron_sources,
  dependencies: hadron_deps,
       install: true,
)
