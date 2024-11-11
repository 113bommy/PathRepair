N,M=map(int,input().split())
L=2**N
l=[float("inf")]*L
l[0]=0
r=(1,2,4,8,16,32,64,128,256,512,1024,2048)
for i in range(M):
    s=0
    a,b=map(int,input().split())
    c=tuple(map(int,input().split()))
    for j in c:
        s+=r[j-1]
    for j in range(L):
        l[j|s]=min(l[j|s],l[j]+a)
if l[-1]=="inf":
    print(-1)
else:
    print(l[-1])