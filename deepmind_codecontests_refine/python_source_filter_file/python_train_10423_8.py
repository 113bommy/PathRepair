from math import ceil,sqrt,gcd
def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().strip().split(" "))
def li(): return list(mi())
n=ii()
s=si()
s1=0
s2=0
f=0
b=[]
b1=0
for i in s:
    if(i=='G'):
        b1+=1
i=0 
f1=0
s1=0
for i in range(n):
    if(s[i]=='G'):
        if(f1==0):
            s1+=1
        else:
            s2+=1
        f=1
    if(s[i]=='S' and f):
        if(f1==0):
            s2=0
            f1=1
        else:
            b.append(s1+1+s2)
            s1=s2
            s2=0
if(f1):
    b.append(s2+1)
else:
    b.append(s1+1)
print(min(max(b),b1))