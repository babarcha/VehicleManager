# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtVehicle_QTableView_Theme_Model_Year_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtVehicle_QTableView_Theme_Model_Year_autogen.dir\\ParseCache.txt"
  "QtVehicle_QTableView_Theme_Model_Year_autogen"
  )
endif()
