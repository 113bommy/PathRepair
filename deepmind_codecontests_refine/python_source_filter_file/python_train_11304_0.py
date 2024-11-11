t = int(input())
for i in range(t):
    a,b = [int(i) for i in input().split()]
    b *= 4
    if(a == 0 and b == 0):
        print(1)
    elif(a == 0):
        print(0)
    else:
        ans = 0.5
        if(a > b):
            ans += (a-b)/a/2 + b/a/4
        else:
            ans += a/b/4
        print(ans)
