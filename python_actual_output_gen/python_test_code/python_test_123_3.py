t=int(input())
while t:
    t-=1
    n=int(input())
    flag=0
    a=[int(x) for x in input().split()]
    for i in range(1,n-1):
        if(a[i-1]<a[i] and a[i]>a[i+1]):
            print("YES")
            print(i-1,i,i+1)
            flag=1
            break
    if(flag==0):
        print("NO")
