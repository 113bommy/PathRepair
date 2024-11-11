n = int(input())
s = input()
x, y, a = 0, 0, 0

for char in s:
    if char == '(': x += 1
    else: y += 1
    a = min(a, x-y)
    b = x-y
ans = '('*(-b) + s + ')'*(a-b)
print(ans)