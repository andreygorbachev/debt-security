project("${PROJECT_NAME}_test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  ANBIMA.cpp
  yield_methodology.cpp
  setup.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  debt-security_yield-methodology
  debt-security_bill
  debt-security_quote
  calendar
  fin-calendar_cash-flow # should probably be FinCalendar::cash-flow
  fin-calendar_business-day-convention # should probably be FinCalendar::business-day-convention
  fin-calendar_day-count # should probably be FinCalendar::day-count
  reset
  Boost::config
  Boost::multiprecision
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
