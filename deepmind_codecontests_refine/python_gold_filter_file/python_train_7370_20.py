import collections 
N=int(input())
T=[list(map(int,input().split())) for _ in range(N)]
T.sort(reverse=True)
TMP=[]
if N==1:
    print(1)
else:
    for i in range(N-1):
        for b in range(i,N-1):
            TMP.append((T[i][0]-T[b+1][0],T[i][1]-T[b+1][1]))
    c=collections.Counter(TMP)
    print(N-c.most_common(n=1)[0][1])