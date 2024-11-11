n = int(input())
if n > 36:
    print("-1")
elif n <= 36 and n > 18:
    n -= 18
    for i in range(n):
        print("8", end="")
    for i in range(18-n):
        print("6", end="")
elif n==0:
    print("-1")
else:
    for i in range(n):
        print("6", end="")