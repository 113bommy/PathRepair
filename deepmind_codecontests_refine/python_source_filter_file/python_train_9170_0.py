n,q=map(int, input().strip().split(" "))
print(n,q)
a=[]
for i in range(q):
    
    x,y=map(int, input().strip().split(" "))
    a.append([x,y])   

if n%2==0:
    for x,y in a:
        # if x+y==2:
        #     print(1)
        #     continue
        if (x+y)%2==0:
            k=0
        else:
            k=(n*n)//2
        k = k
        l=(x-1)*n//2
        m= int(y/2 + 0.5)
        print(k+l+m)
else:
    for x,y in a:
        if (x+y)%2==0:
            k=0
            l = ((x-1)//2)*n 
            p= (x-1)%2*int(n/2+.5)
            m=int(y/2 + 0.5)
            print(k+l+m+p)
            continue
        else:
            k=(n*n)//2 +1
            l = ((x-1)//2)*n 
            p= (x-1)%2*int(n/2-.5) 
            m=int(y/2 + 0.5)
            print(k+l+m+p)