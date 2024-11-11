n,b,d = map(int,input().split())
a = list(map(int,input().split()))
sum = 0
ans = 0
for i in range(n):
    if(a[i] <= b):
        sum += a[i]
        if(sum > d):
            sum = 0
            ans += 1
print(ans)