
N=int(input())
A=list(map(int,input().split()))
Q=int(input())

arg=[0]*(100005)
for a in A:
    arg[a]+=1
ans=sum(A)
for _ in range(Q):
    a,b=map(int,input().split())
    ans+=arg[a]*(b-a)
    print(ans)
    arg[b]+=arg[a]
    arg[a]=0
