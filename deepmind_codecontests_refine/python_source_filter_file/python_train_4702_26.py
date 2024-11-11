import math
n=int(input())
l=1
l1=[]
ans=0
d=math.pow(2,32)-1
f=False
for i in range(n) :
    s=input().split()
    if s[0]=="add" :
        if f :
            print("OVERFLOW!!!")
            exit()
        ans+=l
    if s[0]=="for" :
        w=int(s[1])
        if d<l :
            f=True
            l1.append([w,0])
        else:
            l*=w
            l1.append([w,1])
        
    if s[0]=="end" :
        if l1[-1][1]==1 :
            l/=l1[-1][0]
        else :
            if l1[-2]==1 :
                f=False
        l1.pop()
        
    if ans>d :
        print("OVERFLOW!!!")
        exit()
print(int(ans))
        
        
    
