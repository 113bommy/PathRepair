n = int(input())
left_open = 0
right_open = 0
for i in range(n):
    left, right = map(int, input().split())
    left_open += left
    right_open += right
score = 0
if left_open > n//2:
    score += n - left_open
else:
    score = left_open

if right_open > n//2:
    score += n - right_open
else:
    score = right_open

print(score)