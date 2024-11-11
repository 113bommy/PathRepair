n,m = map(int,input().split())
for i in range(n):
    if i % 2 == 0:
        if i % 4 == 0:
            print("#"+"."*(m-1))
        else:
            print("."*(m-1)+"#")
    else:
        print("#"*m)