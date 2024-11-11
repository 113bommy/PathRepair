import sys,math
n=int(sys.stdin.readline())
l=list(map(int,sys.stdin.readline().split()))
ans=[0]*n
k=[]
for i in range(n):
    if l[i]==0:
        k.append(i)
        ans[i]=0
j=-1
for i in range(n):
    if l[i]!=0:
        if i<k[0]:
            ans[i]=k[0]-i 
        elif i>k[-1]:
            ans[i]=i-k[-1]
        else:
            ans[i]=min(i-k[j],k[j+1]-i)
    else:
        j+=1 
print(*ans)        