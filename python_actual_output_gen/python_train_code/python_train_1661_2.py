x = int(input())
a = list(map(int,input().split()))
b = sorted(a)

if((b[-1]) >= (b[0]+b[-2])):
    print("NO")
else:
    print("YES")
    tmp = b[-2]
    b[-2] = b[-1]
    b[-1] = tmp
    print(*b)