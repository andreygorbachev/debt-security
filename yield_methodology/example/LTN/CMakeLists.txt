project("${PROJECT_NAME}_LTN" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  LTN.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  debt-security_yield-methodology
  debt-security_bill
  debt-security_quote
  calendar_static-data
  fin-calendar_cash-flow # should probably be FinCalendar::cash-flow
  fin-calendar_business-day-convention # should probably be FinCalendar::business-day-convention
  fin-calendar_day-count # should probably be FinCalendar::day-count
  reset
  Boost::config
  Boost::multiprecision
)
