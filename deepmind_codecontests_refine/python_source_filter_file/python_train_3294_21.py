#Poliv
t=int(input())
ans=[]
for i in range(t):
    n,k=map(int,input().split())
    kran=list(map(int,input().split()))
    kran.append(1)
    kran.append(n)
    kran.sort()
    dist=[]
    dist.append(kran[1]-kran[0]+1)
    dist.append(kran[k+1]-kran[k]+1)
    for i in range(2,k+1):
        dist.append(((kran[i]-kran[i+1])//2)+1)
    dist.sort(reverse=1)
    ans.append(dist[0])
for i in ans:
    print(i)