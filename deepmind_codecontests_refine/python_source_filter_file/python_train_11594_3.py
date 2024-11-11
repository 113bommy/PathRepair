def power(a, b):
    if b == 0:
        return 1
    elif b % 2 == 0:
        a_1 = a * a
        return pow(a_1, b // 2)
    return a * pow(a, b - 1)


def k_fib(s, k):
    result = list()
    if k >= 40:
        fibs = [power(2, i) for i in range(40)]
    else:
        fibs = [0] * (k - 1) + [1]
        while fibs[len(fibs) - 1] < s:
            fibs.append(sum(fibs[-k:]))
    while s > 0:
        if fibs[len(fibs) - 1] <= s:
            result.append(fibs[len(fibs) - 1])
            s -= fibs[len(fibs) - 1]
        fibs.pop()
    return result


S, K = [int(j) for j in input().split()]
print(len(k_fib(S, K)))
print(*k_fib(S, K))
