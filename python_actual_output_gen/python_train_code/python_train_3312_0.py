t=int(input())
o=0
while o!=t:
    o+=1
    a=int(input())
    n=list(map(int,input().split()))
    b=0
    for i in range(a):
        if n[i-1]*2<n[i]:
            g=n[i-1]
            while g*2<n[i]:
                g=g*2
                b+=1
        if n[i]*2<n[i-1]:
            g=n[i]
            while g*2<n[i-1]:
                g=g*2
                b+=1
    print(b)