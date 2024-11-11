n = int(input())
x = 0
for i in range(n):
    s = input()
    if len(s) == 3 and "x" in s:
        if "++" in s:
            x += 1
        elif "--" in s:
            x -= 1
        else:
            x = x
print(x)