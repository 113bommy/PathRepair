n,a,b = map(int,input().split())
ans = 0
for i in range(n+1):
    if a <= sum(map(int,sorted(str(i)))) <= b:
        ans += i
print(ans)
