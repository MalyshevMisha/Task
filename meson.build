project('tech_task', 'cpp',
     default_options : ('cpp_std=c++2a'))

project_sources = []

inc = []

subdir('Person')
subdir('Activity')
subdir('Test')

executable('tusk', sources : ['main.cpp', project_sources], 
            include_directories : inc)