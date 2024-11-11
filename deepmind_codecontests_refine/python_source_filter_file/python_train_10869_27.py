n = int(input())
ai = list(map(int,input().split()))
num = max(ai)
ans = 1
for i in range(1,n):
    if abs(ai[i] - ai[i-1]) < num:
        num = ai[i] - ai[i-1]
        ans = i
if abs(ai[0] - ai[-1]) < num:
    print(1,n)
else:
    print(ans,ans+1)
