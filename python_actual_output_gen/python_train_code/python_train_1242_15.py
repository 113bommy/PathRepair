n,m = map(int,input().split())

if n==1 and m==1:
    print (1)
elif (m-1)>n-m:
    print (m-1)
else:
    print (m+1)