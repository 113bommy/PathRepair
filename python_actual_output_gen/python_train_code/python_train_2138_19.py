a = -3
N = int(input())
arr = [int(i) for i in input().split()]
for i in arr:
    if i == 1:
        a = 0
if a == -3:
    print(2)
else:
    print(-1)
