test_sources = files('Source/PersonTest.cpp')

gtest_dep = dependency('gtest', main : true, required : false)
gmock_dep = dependency('gmock')


Person_test = executable('task_test', 
                        sources :  [test_sources, project_sources],
                        dependencies : [gtest_dep, 
                                        gmock_dep], 
                        include_directories :  inc)
test('Person_test', Person_test)