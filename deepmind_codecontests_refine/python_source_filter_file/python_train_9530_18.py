n  = int(input())
k = 0
for i in range(n):
    c,a,b = map(str,input().split())
    a = int(a)
    b = int(b)
    if a < 2400:
        k += 1
    elif a >= 2400 and b <= a:
        k += 1
    elif a > 2400 and b > a:
        print("YES")
        break
if k == n:
    print("NO")