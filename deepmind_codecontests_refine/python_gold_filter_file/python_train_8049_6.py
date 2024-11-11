n=int(input())
a=[0] + list(map(int,input().split()))
m=sum(a)
for i in range(2,int(n**0.5)+ 1):
    # print(i)
    if n%i==0:
        x=i
        y=n//i
        a1=0
        # a2=0
        if n//x>=3:
            for j in range(1,x+1):
                a1=0
                for k in range(j,n+1,x):
                    a1+=a[k]
                m=max(m,a1)
                # print(a1,x)    
        if n//y>=3:
            for j in range(1,y+1):
                a1=0
                for k in range(j,n+1,y):
                    a1+=a[k]
                m=max(m,a1)
                # print(a1,y)

print(m)            
            
            
        