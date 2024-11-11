n = int(input())
left = 0
right = 0
for i in range(n):
    x, y = [int(i) for i in input().split()]

    if x > 0:
        right += 1
    else:
        left += 1
if left == 1 or right == 1:
    print("YES")
else:
    print("NO")
