n = int(input())
a = list(map(int,input().split()))
if n&1 == 1:
    if a[0]&1 == 1 and a[n-1]&1 == 1:
        print("Yes")

    else:
        print("No")
else:
    print("No")
