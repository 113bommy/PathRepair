n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in range(n):
    ans ^= a[i]

if ans == 0:
    print("Yes")
else:
    print("No")
