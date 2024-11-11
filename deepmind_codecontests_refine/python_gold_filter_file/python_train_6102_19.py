n = int(input())
L = list( map(int, input().split()))
if n%2 == 0:
    print("No")
else:
    if L[0]%2 != 0 and L[n-1]%2 != 0:
        print("Yes")
    else:
        print("No")