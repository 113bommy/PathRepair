n,k=map(int,input().split(" "))
arr=list(map(int,input().split(" ")))
mi=min(arr)
ma=max(arr)

if ma-mi>k:
    print("NO")
else:
    print("YES")
    for x in arr:
        for y in range(0,x):
            print(y%k+1,end="")
        print()
