n = int(input())
if n == 0:
    print(n)
elif (n + 1) % 2 == 0:
    print(int((n + 1)//2))
else:
    print(n + 1)
