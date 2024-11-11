n,k=map(int,input().split())
buc=list(map(int,input().split()))
l=[]
for i in range(n):
    if k%buc[i]==0:
        l.append(buc[i])
l.sort()
print(int(k/l[-1]))