/*
这段GO语言代码将实现如下功能：接收用户指定的年份，并打印出此年的日历
*/
package main //打包成可执行文件放在main包下

import (
	"fmt" //导入系统包fmt
)

func printWeek() {
	fmt.Println("(1)(2)(3)(4)(5)(6)(7)")
}

func printMonth(m int) {
	months := []string{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}
	fmt.Println(months[m-1])
}

func printCalendar(year int) {
	firstDay := func(year int) int {
		if year >= 2024 {
			return (year - 2024 + 1 + (year-2021)/4) % 7 //计算2024及之后年份的一月一日是星期几
		}
		return (980000 + 1 - (2024 - year) - (2024-year)/4) % 7 //计算2024年之前年份的一月一日是星期几
	}

	firstDayOfMonth := firstDay(year)

	if firstDayOfMonth == 0 {
		firstDayOfMonth = 7
	}

	for month := 1; month <= 12; month++ { //按月份来输出日历
		printMonth(month)
		printWeek()

		days := 0
		switch month { //计算本月份的天数
		case 1, 3, 5, 7, 8, 10, 12:
			days = 31
		case 4, 6, 9, 11:
			days = 30
		case 2:
			if year%4 != 0 || (year%100 == 0 && year%400 != 0) {
				days = 28
			} else {
				days = 29
			}
		}

		for i := 1; i < firstDayOfMonth; i++ {
			fmt.Printf("   ")
		}
		var change_number = firstDayOfMonth - 1 //此变量用于打印完星期天对应的日期后换行

		firstDayOfMonth = (firstDayOfMonth + days) % 7 //计算下个月的一号是星期几

		if firstDayOfMonth == 0 {
			firstDayOfMonth = 7 //当第一天是星期天时对7取余是0，所以重新进行赋值
		}

		for day := 1; day <= days; day++ {
			if day < 10 {
				fmt.Printf(" %d ", day)
			}
			if day >= 10 {
				fmt.Printf(" %d", day)
			}

			change_number++ //每打印完一个日期，此变量加1

			if change_number == 7 {
				fmt.Println() //换行
				change_number = 0
			}
		}
		//使用两个换行符来进行月份直接的分隔
		fmt.Print("\n\n")
	}
}

func main() {
	var year int
	fmt.Print("Enter a year: ")
	fmt.Scan(&year) //接收用户的输入年份
	printCalendar(year)
}
