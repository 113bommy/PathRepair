a, b = map(int, input().split())
if a + b == 15:
    print("+")
    exit()
elif a * b == 15:
    print("*")
    exit()
else:
    print("×")