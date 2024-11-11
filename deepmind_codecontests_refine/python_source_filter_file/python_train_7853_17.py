n=int(input())
l=[int(x) for x in input().split()]
l.sort()
if(n==2):
    print(l[1]-l[0],'1')
else :
    i,x=1,1
    while(i<n and l[i]==l[0]):
        x+=1
        i+=1
    i,y=n-2,1
    while(i>=0 and l[i]==l[n-1]):
        y+=1
        i-=1
    if(x==y and y==n):
        print('0',n*(n-1)/2)
    else:
        print(l[n-1]-l[0],x*y)