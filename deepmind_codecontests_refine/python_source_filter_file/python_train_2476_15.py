a = list(map(int,input().split()))
if -(a[0]//a[3]) >= -(a[2]//a[1]):
    print("Yes")
else:
    print("No")