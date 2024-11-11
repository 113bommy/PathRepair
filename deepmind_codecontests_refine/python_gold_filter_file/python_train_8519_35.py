n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
c=0
if(b[n-1]-b[0]>1):
    print('No')
elif(b[n-1]-b[0]==0):
    if(1<=b[0]<=n//2 or b[0]==n-1):
        print('Yes')
    else:
        print('No')
else:
    for i in range(n-1):
        if(b[i]<b[i+1]):
            c=i
            break
    if(c==n-2):
        print('No')
    elif(c+1<=b[0]<=c+(n-c-1)//2):
        print('Yes')        
    else:
        print('No')