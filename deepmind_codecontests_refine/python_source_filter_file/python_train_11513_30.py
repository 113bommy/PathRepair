l="abcdefghijklmnopqrstuvwxyz"
l=list(l)
ans=[]
n,k=map(int,input().split())
for i in range(k):
    ans.append(l[i])
k=n-k
for i in range(2,k+2):
    ans.insert(2*i,l[i%(n-k)])
print(''.join(ans))
