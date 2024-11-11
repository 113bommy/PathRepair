n = int(input())
a = list(map(lambda x:int(x)-1,input()))
ans = 0
for i in range(n):
    if (n-1) & i == i:
        ans += a[i]
if ans % 2 == 1:
    print(1)
else:
    if a.count(1) != 0:
        print(0)
    else:
        ans = 0
        b = map(lambda x:x//2,a)
        for i in range(n):
            if (n-1) & i == i:
                ans += b[i]
        if ans % 2 == 1:
            print(2)
        else:
            print(0)