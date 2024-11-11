n = int(input())
left_opened = 0
right_opened = 0
for _ in range(n):
    l, r = map(int, input().split())
    left_opened += l
    right_opened += r

left = min(left_opened, n - left_opened)
right = min(left_opened, n - right_opened)
print(left + right)
