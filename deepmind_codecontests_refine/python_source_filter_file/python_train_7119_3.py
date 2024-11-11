from datetime import date

a = list(map(int, input().split(':')))
b = list(map(int, input().split(':')))

f_date = date(a[0],a[1],a[2])
l_date = date(b[0], b[1], b[2])
delta = l_date - f_date
print(delta.days)


