n = int(input())
mas = list(map(int, input().split()))
a = 0
b = 10000000
for el in mas:
    if el <= 500000:
        if el > a:
            a = el
    else:
        if el < b:
            b = el
b = 1000000 - b
a = a - 1
if a > b:
    print(a)
else:
    print(b)