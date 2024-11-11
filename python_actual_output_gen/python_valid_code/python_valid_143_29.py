n = int(input())
a = list(map(int, input().split()))

b = 0
if(len(a) == 1):
    if(a[0]==1):
        print("YES")
    else:
        print("NO")
else:
    for i in range(len(a)):
        if(a[i] == 0):
            b += 1
    if(b <= 1):
        print("YES")
    else:
        print("NO")