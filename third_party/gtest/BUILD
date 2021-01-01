prebuilt_cc_library(
  name = 'gtest',
  hdrs = ['include/*.h'] + ['include/internal/*.h'],
  deps = ['#pthread']
)

prebuilt_cc_library(
  name = 'gtest_main',
  hdrs = ['include/*.h'] + ['include/internal/*.h'],
  deps = [':gtest']
)
