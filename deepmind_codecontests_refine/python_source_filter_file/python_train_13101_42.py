N,C,K = map(int, input().split())
T = [int(input()) for i in range(N)]
T.sort()
ans=s=0
while s<N:
    t=T[s]+K
    sm=1
    for i in range(s+1,s+c):
        if T[i]<t:
            sm+=1
        else:
            break
    s+=sm
    ans+=1
print(ans)
