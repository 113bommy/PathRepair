N,A,B,C=map(int,input().split())
l=[]

for i in range(N):
l.append(int(input()))
INF=100000

def mp(j,a,b,c):
    if j==N:
      return abs(a-A)+abs(b-B)+abs(c-C)-30 if min(a,b,c)>0 else INF
    ret0=mp(j+1,a,b,c)
    ret1=mp(j+1,a+l[j],b,c)+10
    ret2=mp(j+1,a,b+l[j],c)+10
    ret3=mp(j+1,a,b,c+l[j])+10
    return min(ret0,ret1,ret2,ret3)
print(mp(0,0,0,0))