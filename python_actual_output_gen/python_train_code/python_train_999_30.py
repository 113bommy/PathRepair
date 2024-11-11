n=int(input())
s=list(map(int,input().split()))
maxx=2
i=2
p=0
w=2


while i<n:
    
    if s[i]==s[i-1]+s[i-2]:
        w+=1
        i+=1
        p=1
    else:
        if p==1:
            if w>maxx:
                maxx=w 
                w=2
        i+=1 
        p=0
if w>maxx:
    maxx=w
if n==1:
    print("1")
elif n==2:
    print("2")
else:    
    print(maxx)    
    
    
    
    