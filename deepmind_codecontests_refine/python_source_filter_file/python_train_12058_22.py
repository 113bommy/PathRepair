N=int(input())
S=[input() for i in range(N)]
print(S)
ans='Yes'
if len(set(S))!=N:
    ans='No'
for i in range(N-1):
    if S[i][-1]!=S[i+1][0]:
        ans='No'
print(ans)