import math
def countDivisors(n) : 
    l={}
    for i in range(1, int((math.sqrt(n)) + 1)) : 
        if (n % i == 0) : 
              
            # If divisors are equal, 
            # count only one 
            if (n / i == i) : 
                l[i]=0
            else : # Otherwise count both 
                l[i]=0
                l[n//i]=0
    return l
n,m,k=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
j=0
c1,c2=0,0
f1=0
f2=0
a1=[0 for i in range(n+1)]
a2=[0 for i in range(m+1)]
while j<max(n,m):
    if f1<n:
        if l1[j]==1:
            c1+=1
        else:
            if c1!=0:
                a1[c1]+=1
            c1=0
    if f2<m:
        if l2[j]==1:
            c2+=1
        else:
            if c2!=0:
                a2[c2]+=1
            c2=0
    j+=1
    f1+=1
    f2+=1
if c1!=0:
    a1[c1]+=1
if c2!=0:
    a2[c2]+=1

l3=countDivisors(k)
l4=l3.copy()
ans=[0 for i in range(n)]
for i in range(m+1):
    if i<n+1 and a1[i]>0:
        for j in sorted(l3.keys()):
            if i>=j:
                l3[j]+=(a1[i]*(i-j+1))
                continue
            break
    if i<m+1 and a2[i]>0:
        for j in sorted(l4.keys()):
            if i>=j:
                l4[j]+=(a2[i]*(i-j+1))
                continue
            break
c=0
'''print(l3,l4)
print(a1,a2)'''
for i in l3:
    c+=(l3[i]*l4[k//i])
print(c)
    
        

        
    