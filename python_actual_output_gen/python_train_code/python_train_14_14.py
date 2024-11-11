a,b = map(int,input().split())
sumh = a
while a>=1:
    sumh = sumh + int(a / b)
    a = a / b
print(sumh)

