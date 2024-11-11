n,m=map(int,input().split())
ar=list(map(int,input().split()))
p=[]
for i in range(1,n):
    p.append(ar[i]-ar[i-1])
p.sort()
print(sum(p[:n-m]))