n = int(input()) - 1
fib = [1, 1] + [0] * n
for i in range(n):
    fib[i] = fib[i-1] + fib[i-2]
print(fib[n])