a, b = [int(i) for i in input().split()]
if a >= b:
    style = b
    same = int((a-b) / 2)
else:
    style = a
    same = int((b-a) / 2)
print(style, same)