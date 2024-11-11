n = int(input())
ai = list(map(int,input().split()))
ai.sort()
ans = ai[0] != 0
for i in range(1,n):
    ans += (ai[i-1] != ai[i])
print(ans)
