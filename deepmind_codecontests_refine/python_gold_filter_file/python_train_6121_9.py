n = int(input())
s = list(map(int,input().split()))

ans = [0]*n
for i in range(n):
    ans[s[i]-1] = i+1

print(*ans)