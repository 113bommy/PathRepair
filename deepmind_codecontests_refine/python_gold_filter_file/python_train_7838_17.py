n=int(input())
list1=list(map(int,input().split()))
list1.sort()
list1.reverse()
k=0
m=0
t=0
for i in list1 :
    t=t+i    
if n==0 :
    print(0)
elif n>t :
    print(-1)
else :    
    for i in list1 :
        k=k+i
        m=m+1
        if k>=n :
            break
    print(m)        
