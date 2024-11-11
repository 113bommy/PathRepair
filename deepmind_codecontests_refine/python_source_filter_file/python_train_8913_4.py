n=int(input())
a=list(map(int,input().split()))
if 1 not in a:
    print("0")
elif 2 not in a:
    print(n//3)
else:
    x=a.count(1)
    y=a.count(2)
    if y>=x:
        print(x)
    else:
        print(x + ((x-y)//3))