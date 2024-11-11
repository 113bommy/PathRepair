y1, m1, d1 = map(int, input().split(':'))
y2, m2, d2 = map(int, input().split(':'))
from datetime import  date
a = date(y1, m1, d1)
b = date(y2, m2, d2)
#datetime.timedelta(7)
print((b-a).days)
