def rom(n):
    if n==1:
        return 1
    return 2**n+rom(n-1)
n = int(input())
print(rom(n))