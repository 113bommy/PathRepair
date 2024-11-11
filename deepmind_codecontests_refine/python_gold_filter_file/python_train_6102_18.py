n = int(input())
p = list(map(int, input().split()))
if n % 2 != 0 and p[0] % 2 != 0 and p[-1] % 2 != 0:
    print("Yes")
else:
    print("No")