n = (int(input()))
x = 0
for i in range(0,n):
    op = input()
    if op == "x++" or op == "++x":
        x += 1
    elif op == "x--" or op == "--x":
        x -= 1
print(x)