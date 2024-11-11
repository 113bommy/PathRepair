lines = int(input())
x = 0

for i in range(lines):
    op = input()
    if op == "++X" or "X++":
        x = x + 1
    else:
        x = x - 1

print(x)