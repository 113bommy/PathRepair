import math
n=int(input())
j=1
l=[]
for i in range(2,math.ceil(math.sqrt(n))+1):
    if n%i==0:
        if n//i==i:
            l.append(i)
        else:
            if i!=n:
                l.append(i)
            if n//i!=1:
                l.append(n//i)
l.sort()
n1=len(l)
mini=n
if n1>1:
    mini=l[0]
for i in range(n1-1):
    mini=min(l[i+1]-l[i],mini)
for i in range(n1):
    for j  in range(i+1,n1):
        if math.gcd(l[i],n//l[i])==1:
            mini=1
            break    
print(max(mini,1))    