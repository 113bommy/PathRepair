n,m=map(int, input().split())
for i in range(1,n+1):
    if i%2==1:
        print("#"*m)
    elif i%4==2:
        print("."*(m-1)+"#")
    elif i%4==4:
        print("#"+"."*(m-1))