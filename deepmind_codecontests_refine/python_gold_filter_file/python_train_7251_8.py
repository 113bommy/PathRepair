I=lambda:map(int,input().split())
n,s=I()
l=[0]
for i in range(n):
    q,w=I()
    q=q*60+w
    l+=[q]
if l[1]-l[0]>s:exit(print(0, 0))
for i in range(n):
    if l[i+1]-l[i]>2*s+1:
        l[i]+=s+1
        exit(print(l[i]//60,l[i]%60))
l[-1]+=s+1
print(l[-1]//60,l[-1]%60)