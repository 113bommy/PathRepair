n = int(input())
print(1 if n == 0 else len(str(bin(n))[2:]))