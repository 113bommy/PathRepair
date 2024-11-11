def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

import math 
  
def pr(n): 
    a=[]
    while n % 2 == 0: 
        a.append(2) 
        n = n / 2
          
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        while n % i== 0: 
            a.append(i) 
            n = n / i 
              
    if n > 2: 
        a.append(n) 
    return list(set(a))
      

n=int(input())
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))
if n==1:
    print(a[0][0])
else:
    b=[]
    b.append(pr(a[0][0]))
    b.append(pr(a[0][1]))
    c=set([])
    for i in range(len(b)):
        for j in range(len(b[i])):
            c.add(b[i][j])
    c=list(c)
    e=0
    for i in range(len(c)):
        b=0
        for j in range(n):
            if a[j][0]%c[i]==0 or a[j][1]%c[i]==0:
                b+=1
        if b==n:
            e=1
            print(c[i])
            break
    if e==0:
        print(-1)