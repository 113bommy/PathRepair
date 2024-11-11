n,m=map(int,input().split())
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]
j=0
maxcap=a[j]
currrooms=1
maxrooms=0
for i in range(m):
    while b[i]>maxcap:
        maxrooms=maxcap
        j+=1
        maxcap+=a[j]
        currrooms+=1
    print(currrooms,b[i]-maxrooms)