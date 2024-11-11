n=int(input())
a=[int(i)for  i in input().split()]
s=sum(a)//2
b=[[a[i-1],i]for i in range(1,n+1)]
b.sort()
for i in range(1,n):
    if b[i-1][0]<=s<=b[i][0]:
        k=i-1
        break
else:
    k=n-1
ans=[]
num=0
for i in range(n):
    while k>=0 and b[k][0]>s-b[i][0]/2:
        k-=1
    if k==-1:
        break
    if b[k][0]==s-b[i][0]/2:
        if k==i:
            if b[k-1][0]==b[k][0]:
                ans.append(b[i][1])
                num+=1
        else:
            ans.append(b[i][1])
            num+=1
print(num)
print(' '.join([str(r)for r in ans]))
        
