# Eleven
def stranger(n):
    if n == 1:
        return 'O'
    ans = ""
    fib = [i for i in range(n+1)]
    fib[0] = 1
    fib[1] = 1
    for i in range(2, n+1):
        fib[i] = fib[i-1] + fib[i-2]
    for i in range(1, n+1):
        if i in fib:
            ans += 'O'
        else:
            ans += 'o'
    return ans

n = int(input())
print(stranger(n))