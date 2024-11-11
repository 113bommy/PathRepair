n, k = map(int, input().split())
a = list(map(int, input().split()))
ans=1
for num in a:
    if k%num==0:
        ans = max(ans, num)
print(int(k/ans))