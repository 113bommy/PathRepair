n = int(input())
print(0 if n == 0 else len(str(bin(n))[2:]))