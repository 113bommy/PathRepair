from operator import itemgetter
N=int(input())
R=[list(map(int,input().split())) for n in range(N)]
B=[list(map(int,input().split())) for n in range(N)]

sorted(R,key=itemgetter(1),reverse=True)
B.sort()
ans=0

for c,d in B :
    for a,b in R :
        if a<c and b<d :
            ans+=1
            R.remove([a,b])
            break

print(ans)