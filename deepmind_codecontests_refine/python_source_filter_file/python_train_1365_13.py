N,D=map(int,input().split())
ranking=list(map(int,input().split()))
scores=list(map(int,input().split()))
Ds=ranking[D-1]+scores[0]
ranking.sort()
import bisect
new=bisect.bisect_left(ranking,Ds,0,N)
daiding=ranking[N+1-D:new]
m=0
for i in daiding[::-1]:
    if i+scores[-1]<=Ds:
        del(scores[-1])
        m+=1
print(D-m)