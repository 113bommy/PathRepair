N=int(input())
n=input().split()

gg=[]
for i in range (N):
    for j in range (i-1,N):
        l=0
        p=0
        for s in range (i,j+1):
            if int(n[s])==0:
                l=l+1
            if int(n[s])==1:
                p=p+1
        gg.append(l-p)
        
j=max(gg)
f=0
for i in range (N):
    if int(n[i])==1:
        f=f+1
print(f+j)

