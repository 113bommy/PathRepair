# cook your dish here

n,k=map(int,input().split())
d={}
while(n>0):
    s=input()
    k1=len(s)
    if k1 not in d:
        d[k1]=1
    else:
        d[k1]+=1
    n-=1
s=input()
k1=len(s)
#print(d)
c=c1=0
for i in sorted(d):
    if i<k1:
        c+=d[i]
    elif i==k1:
        c1=c
        c+=d[i]
    else:
        break

print(c1+1+(c1//k)*5,c+((c-1)//k)*5)
        
