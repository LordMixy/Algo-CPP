project(
	'Algo',
	['cpp'],
	default_options: ['cpp_std=c++20']
)

# 'warning_level=everything'
# default_options: ['cpp_std=c++17', 'warning_level=everything']

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

source = []
subdir('src')

exe = executable(
  'algotest',
  ['./tests/algotest.cpp'],
  dependencies : [gtest_dep],
)    

executable('Algo', source)
test('gtest tests', exe)
