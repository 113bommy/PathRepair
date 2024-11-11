t=int(input())
for i in range(t):
    n=int(input())
    c=1
    a=list(map(int,input().split()))[:n]
    for i in range(len(a)):
        for j in range(i,len(a)):
            if abs(a[i]-a[j])==1:
                c=c+1
            
    if c>2:
        print(2)
    else:
        print(c)
