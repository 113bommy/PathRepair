import math
s=(input())
I=lambda : list(map(int,input().strip().split(' ')))
a,b=I()
                                                                                                                            
n=len(s)
na=len(str(a))
nb=len(str(b))

A=[None]*n
B=[None]*n

#Fill A: remainder array of the number


if int(s[:na])>=a:
    start=na
    r=int(s[:na])%a
else:
    start=na+1
    r=int(s[:na+1])%a
        
A[start-1]=r
for i in range(start,n):
    r=int(str(r)+s[i])%a
    A[i]=r


if nb>1 and int(s[n-nb+1:])>=b:
    end=n-nb+1
elif nb==1 and int(s[-1])>=b:
    end=n-1
else:
    end=n-nb

    
r=int(s[end:])%b

B[end]=r

for i in range(end-1,-1,-1):
    r=(r+ (pow(10,n-i-1,b)*(int(s[i])%b)%b))%b
    B[i]=r

out=0

for i in range(start,min(end+1,n)):
    if i+1<=n-1 and s[i+1]!='0' and A[i]==B[i+1]==0:
        print('YES')
        print(s[:i+1])
        print(s[i+1:])
        out=1
        break
    
if not out:
    print('NO')