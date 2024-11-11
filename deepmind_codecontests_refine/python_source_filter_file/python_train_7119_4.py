from datetime import date

a = str(input())
b = str(input())

adate = a.split(":")
bdate = b.split(":")

da = date(int(adate[0]),int(adate[1]),int(adate[2]))
db = date(int(bdate[0]),int(bdate[1]),int(bdate[2]))

print((db-da).days)