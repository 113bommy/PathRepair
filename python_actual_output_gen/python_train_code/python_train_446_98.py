def countRhombus(i):
    if i <= 1:
        return 1
    return 2**i + countRhombus(i-1)

n = int(input())
print(countRhombus(n))
