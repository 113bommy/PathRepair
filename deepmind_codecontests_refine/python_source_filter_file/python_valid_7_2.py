
import sys
import math
#import random
input=sys.stdin
output=sys.stdout

t=int(input.readline().strip())
for i in range(t):
    n=int(input.readline().strip())
    a=[int(x) for x in input.readline().strip().split()]
#    n=random.randrange(1,100)
#    a=[random.randrange(1,100000000) for x in range(n)]

    bmax=0
    b=[0]*(n-1)
    for j in range(n-1):
        b[j]=a[j]-a[j+1]
        if b[j]<0:
            b[j]=-b[j]
        if b[j]!=1:
            bmax=1    

    if bmax==0:
        print(1)
        continue        

#    def HCF(a, b):
#        if a==0:
#            return b
#        elif b==0:
#            return a
#        elif a>b:
#            return HCF(a%b, b)
#        else:
#            return HCF(b%a, a)

#    def HCF(x, y):
#        while True:
#            if x==0:
#                return y
#            elif y==0:
#                return x
#            elif x>y:
#                x=x%y
#            else:
#                y=y%x

    def HCF(x, y):
        while x>1:
            x, y=y%x, x
        if x==1:
            return 1
        else:        
            return y
        
    St=[[b[x]] for x in range(n-1)]
    upton=1
    while upton<n:
        for j in range(n-upton*2):
            a=HCF(St[j][-1], St[j+upton][-1])
            St[j].append(a)
            if a!=1:
                bmax=upton*2
        upton*=2                                    

 #   total=bmax
 #   c=int(math.log2(bmax))
 #   k=0
 #   while k+total<n:
 #       if St[k][c]!=1:
 #           start=total+1
 #           end=min(n-k-1, bmax*2-1)
 #           while start<=end:
 #               j=(start+end)//2
 #               if HCF(St[k][c], St[k+j-2**c][c])!=1:
 #                   total=j
 #                   start=j+1
 #               else:
 #                   end=j-1    
 #       k+=1

#    def possible_group(x, y):
#        c=b[x]
#        for i in range(x+1, y):
#            c=HCF(c, b[i])
#            if c==1:
#                return False
#        return True        

#    total=bmax
#    start=bmax+1
#    end=min(n-1, bmax*2-1)
#    c=int(math.log2(bmax))
#    upton=2**c
#    while start<=end:
#        j=(start+end)//2
#        for k in range(n-j):            
#            if HCF(St[k][c], St[k+j-upton][c])!=1:
#                total=j
#                start=j+1
#                break
#        if start<=j:
#            end=j-1

    def possible_group(l, r):
        c=int(math.log2(r-l))
        return HCF(St[l][c], St[r-1-2**c][c])!=1

    total=bmax+1
    l=0
    r=total
    while r<n:
        while r-l+1>total and not possible_group(l,r):
            l+=1
        if r-l+1>total:
            total=r-l+1
        r+=1 

    
    print(total)

#    test=0
#    for j in range(1,n):
#        for k in range(n-j):
#            if possible_group(k,k+j):
#                test=j
#                break
#        if test<j:
#            break    

#    if test!=total:
#        print(test,total)        

    

    