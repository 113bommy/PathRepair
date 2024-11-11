n = int(input())
if n == 1:
    print(1)
    print("1 1")
    exit()
if n == 2:
    print(2)
    print("1 1")
    print("1 2")
    exit()

if n % 2 == 1:
    print(n // 2 + 1)
    for i in range(1, n // 2 + 2):
        print(f"1 {i}")
    for i in range(1, n // 2 + 1):
        print(f"{n // 2 + 1} {i + 1}")
else:
    print(n // 2 + 1)
    for i in range(1, n // 2 + 1):
        print(f"1 {i}")
    for i in range(1, n // 2 + 1):
        print(f"{n // 2 + 1} {i}")