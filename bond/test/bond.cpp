// The MIT License (MIT)
//
// Copyright (c) 2025 Andrey Gorbachev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "setup.h"

#include <bond.h>

#include <gtest/gtest.h>

using namespace std;
using namespace std::chrono;
using namespace fin_calendar;


namespace debt_security
{

	TEST(bond, constructor1)
	{
		const auto issue_date = 2008y / January / 1d;
		const auto maturity_date = 2014y / January / 1d;
		const auto frequency = SemiAnnual;
		const auto coupon = 10.0;
		const auto& calendar = make_calendar_ANBIMA();
		const auto face = 1000.0;
		const auto b = bond{
			issue_date,
			maturity_date,
			frequency,
			coupon,
			calendar,
			face
		};

		EXPECT_EQ(b.get_issue_date(), issue_date);
		EXPECT_EQ(b.get_maturity_date(), maturity_date);
		EXPECT_EQ(b.get_frequency(), frequency);
		EXPECT_EQ(b.get_coupon(), coupon);
		EXPECT_EQ(b.get_calendar(), calendar);
		EXPECT_EQ(b.get_face(), face);
	}

	TEST(bond, cash_flow1)
	{
		const auto issue_date = 2008y / January / 1d;
		const auto maturity_date = 2014y / January / 1d;
		const auto frequency = SemiAnnual;
		const auto coupon = 10.0;
		const auto& calendar = make_calendar_ANBIMA();
		const auto face = 1000.0;
		const auto b = bond{
			issue_date,
			maturity_date,
			frequency,
			coupon,
			calendar,
			face
		};

		const auto cf = b.cash_flow();

		EXPECT_EQ(cf.get_payment_date(), 2014y / January / 2d);
		EXPECT_EQ(cf.get_amount(), face);
	}

}
