n,m=list(map(int,input().split()))
positive=n-m
negative=m-1
if(n==1 and m==1):
    print(m-1)
elif(positive>negative):
    print(m+1)
elif(negative>=positive):
    print(m-1)
