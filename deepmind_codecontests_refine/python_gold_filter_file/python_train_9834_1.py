n = int(input())
print("+------------------------+")

for i in range(3):
    print("|", end="")
    if i < 2 and i < n or i + 1 < n:
        print("O.", end="")
    else:
        print("#.", end="")
    for j in range(10):
        if n > (4+j*3+i):
            print("O.", end="")
        else:
            print("#.", end="")
    if i == 0:
        print("|D|)")
    elif i == 1:
        print("|.|")
        if 3 <= n:
            print("|O.......................|")
        else:
            print("|#.......................|")
    elif i == 2:
        print("|.|)")

print("+------------------------+")
