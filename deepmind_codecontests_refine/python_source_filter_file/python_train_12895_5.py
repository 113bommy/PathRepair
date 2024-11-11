def sieve(n):
    res = []
    nums = [1] * n
    nums[0] = 0
    for i in range(int(n ** 0.5) + 1):
        if nums[i] == 0: continue
        j = 2
        while (i + 1) * j <= n:
            nums[(i+1) * j - 1] = 0
            j += 1
    for i in range(len(nums)):
        if nums[i] == 1:
            res.append(i+1)
    return res

primes = sieve(50000)

while True:
    try:
        n = int(input())
        minn, maxn = 0, 0
        for i in range(len(primes)):
            if primes[i] > n:
                maxn = primes[i]
                minn = primes[i-1]
                if minn == n: minn = primes[i-2]
                break
        print('%d %d' % (minn, maxn))
    except:
        break