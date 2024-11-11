t = int(input())
for j in range(t):
    n = int(input())
    x = list(map(int, input().split()))
    ans = [0]
    for i in range(1, n):
        k = 0
        otv = 0
        while 2 ** k <= max(x[i], x[i-1]):
            if 2 ** k & x[i-1] == 2**k and 2 ** k & x[i] == 0:
                otv += 2 ** k
                x[i] = x[i] ^ 2**k
            k += 1
        ans.append(otv)
    print(*ans)