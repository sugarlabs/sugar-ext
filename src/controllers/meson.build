api_version = '1.0'

controllers_sources = [
  'sugar-event-controller.c',
  'sugar-long-press-controller.c',
  'sugar-swipe-controller.c',
]

controllers_header = [
  'sugar-event-controllers.h',
  'sugar-event-controller.h',
  'sugar-long-press-controller.h',
  'sugar-swipe-controller.h',
]

controllers_dep = declare_dependency(
              sources: controllers_sources,
  include_directories: include_directories('.'),
         dependencies: dependency('gtk4', version: '>=4.0'),
)

gnome = import('gnome')
enum_types = gnome.mkenums('sugar-enum-types',
         sources: 'sugar-swipe-controller.h',
      c_template: 'sugar-enum-types.c.template',
      h_template: 'sugar-enum-types.h.template',
  install_header: true,
)

sugar_gestures_lib = shared_library('sugar-eventcontroller.' + api_version,
       sources: [controllers_sources, enum_types, controllers_header],
  dependencies: controllers_dep,
       install: true,
)

sugar_gestures_gir = gnome.generate_gir(sugar_gestures_lib,
  export_packages: 'SugarGestures-' + api_version,
  nsversion: api_version,
  namespace: 'SugarGestures',
  symbol_prefix: 'sugar',
  identifier_prefix: 'Sugar',
  #includes: ['Gtk-4.0', 'Gdk-4.0'],
  install: true,
)
