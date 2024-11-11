import datetime

date_list = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

while True:
    m, d = map(int, input().split())
    if m == d == 0:
        break
    print(date_list[datetime.date(2014, m, d).weekday()])

