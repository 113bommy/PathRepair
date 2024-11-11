a,b,n = map(int, input().split())
for i in range(n):
    a*=10
    if a % b == 0:
        print(a * (10**(n - 1)))
        break
    k = (a // b + 1)*b
    if k // 10 == a // 10:
        a = k
    else:
        print(-1)
        break
else:
    print(a)
