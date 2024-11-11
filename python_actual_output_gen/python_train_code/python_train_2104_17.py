n = int(input())
a = list(map(int, input().split()))
if n % 2 != 0 and a[0] % 2 != 0 and a[n-1] != 0:
    print("Yes")
else:
    print("No")