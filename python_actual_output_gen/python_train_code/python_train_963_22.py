n=int(input())
count=0
p=0
u=0
l=list(map(int,input().split()))
for i in l:
    if i>0:
        p+=1
    else:
        if p>0:
            p+=i
        else:
            u+=1
print(u)            
        
    