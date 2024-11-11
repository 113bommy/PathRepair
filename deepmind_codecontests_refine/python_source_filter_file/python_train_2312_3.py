t=int(input())
while t:
    n=int(input())
    p=input().split()
    for i in range(n):
        p[i]=int(p[i])
    a=[]    
    for i in range(min(n//2,n-1)):
        if(p[i]-p[i+1]>0):
            a.append(i)
    if(len(a)>=2):
        g=a[0]
        s=0
        b=0
        for i in range(1,len(a)):
            if(s<=g+1):
                s+=a[i]-a[i-1]
            else:
                b+=a[i]-a[i-1]
        if(s>g and b>g):
            print(g+1,s,b)
        else:
            print(0,0,0)
    else:
        print(0,0,0)
    t-=1    