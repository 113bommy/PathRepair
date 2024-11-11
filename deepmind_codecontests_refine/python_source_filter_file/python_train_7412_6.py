t = int(input())
for i in range(t):
    a,b = list(map(int,input().split()))
    if b > a:
        a,b=b,a
    if ((a+b) % 3 == 0 and a*2 >=b):
        print("YES")
    else:
        print("NO")
