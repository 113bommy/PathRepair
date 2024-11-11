from math import ceil
kub = [int(i) for i in input().split()]
med = [int(i) for i in input().split()]
n = int(input())
kub = sum(kub)
med = sum(med)
kub = ceil(kub / 5)
med = ceil(med / 10)
if kub + med <= 10:
    print("YES")
else: print("NO")