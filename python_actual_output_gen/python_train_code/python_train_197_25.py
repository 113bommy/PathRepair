n=int(input())
for i in range(n):
    c=100000
    d=0
    n,k,d=map(int,input().split())
    l=list(map(int,input().split()))
    for i in range(n-d+1):
        #print(set(l[i:i+d]))
        if len(set(l[i:i+d]))<c:
            c=len(set(l[i:i+d]))
            d+=1
            #print(set(l[i:i+d]))
    if d>=1:
        print(c)
    else:
        print(d)