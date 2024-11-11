n= int(input())

a,b = [int(i) for i in input().split()]
current = max(a,b)
flag = True
for i in range(n-1):
    a,b = [int(i) for i in input().split()]
    ma = max(a,b)
    mi = min(a,b)
    if mi > current:
        print("NO")
        flag = False
        break
    if ma <= current:
        current = ma
    else:
        current = mi

if(flag):
    print("YES")
