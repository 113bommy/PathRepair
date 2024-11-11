n = int(input())

fib = []
fib.append(1)
fib.append(1)
for i in range(2, n + 1):
    if fib[i - 1] + fib[i - 2] > n:
        break
    fib.append(fib[i - 1] + fib[i - 2])

name = ["o" for i in range(n)]
for i in range(len(fib)):
    name[fib[i] - 1] = "O"

print(*name, sep="")
