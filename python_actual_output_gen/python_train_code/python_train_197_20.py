n=int(input())
for i in range(n):
    c=100000
    y=0
    n,k,d=map(int,input().split())
    l=list(map(int,input().split()))
    for i in range(n-d):
        #print(set(l[i:i+d]))
        if len(set(l[i:i+d]))<c:
            c=len(set(l[i:i+d]))
            y+=1
            #print(set(l[i:i+d]))
    if y>=1:
        print(c)
    else:
        print(d)
    