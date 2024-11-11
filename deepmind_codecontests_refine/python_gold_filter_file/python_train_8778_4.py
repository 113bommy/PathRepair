n,m=map(int,input().split())
ai=[]
k=0
v=0
for i in range(m):
    a,b=map(int,input().split())
    ai.append([b,a])
    ai = sorted(ai)[::-1]
for i in ai:
    v=min(i[1],n)
    n-=v 
    k+=(v*i[0])
print(k)