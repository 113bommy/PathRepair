n = int(input())
if n > 34:
    print("-1")
elif n <= 34 and n > 17:
    n -= 17
    for i in range(n):
        print("8", end="")
    for i in range(17-n):
        print("6", end="")
elif n==0:
    print("-1")
else:
    for i in range(n):
        print("6", end="")