n = int(input())
a = [int(d) for d in input().split()]
f = a.count(5)
z = a.count(0)
if z == 0:
    print(-1)
elif z != 0 and f < 3:
    print(0)
else:
    x = (f//3)*3
    ans = [5]*x
    ans.extend([0]*z)
    print(*ans, sep='')
