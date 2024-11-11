T=int(input())
for _ in range(T):
    n=int(input())
    a=input()
    k=[]
    s=a[0]
    for i in range(1,n):
        if (a[i]<s):
            k=[i]
            s=a[i]
        elif(a[i]==s):
            k.append(i)

    b=a
    s=b
    k1=1
    if (n%2==0):
        fo=0
    else:
        fo=1
    
    for i in k:
        if (((i+1)%2==0 and fo==0) or ((i+1)%2!=0 and fo ==1)):
            s=a[i:]+a[i-1::-1]
            if (s<b):
                b=s
                k1=i+1
        else:
            s=a[i:]+a[:i]
            if(s<b):
                b=s
                k1=i+1
        

    print(s)
    print(k1)
                
        
        

    
