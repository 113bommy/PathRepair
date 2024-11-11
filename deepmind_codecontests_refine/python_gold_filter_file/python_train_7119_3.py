from datetime import date
y1,m1,d1 = map(int,input().split(':'))
y2,m2,d2 = map(int,input().split(':'))
date1 = date(y1,m1,d1)
date2 = date(y2,m2,d2)
print(abs((date2-date1).days))
