# for _ in range(int(input())):
#     n=int(input())
print((3**38)//10**18)    
a=[3**i for i in range(39)]
for _ in range(int(input())):
    n=int(input())
    ans=0
    for i in range(38,-1,-1):
        if n-a[i]>=0:
            n-=a[i]
            ans+=a[i]
        elif n-a[i]<0 and  (3**i - 1)//2 <n:
            n-=a[i]
            ans+=a[i]
    print(ans)        
        
        

    