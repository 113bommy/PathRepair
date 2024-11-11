n=int(input())
if n%4==0:
    print(0)
    print(n//4,end=" ")
    i=1
    while i+3<n:
        print(i,end=" ")
        print(i+3,end=" ")
        i+=4
else:
    right=0
    left=0
    ans=[]
    i=2
    while n>0:
        if right>left:
            left+=n
        else:
            ans.append(n)
            right+=n
        n-=1
    print(abs(right-left))
    print(len(ans),*ans)

        
    
    