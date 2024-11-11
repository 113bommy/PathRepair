def main():
    mod, pow3, p = 2**31-1, [1]*200001, 1
    i3 = pow(3, mod-2, mod)
    for i in range(1, 200001):
        pow3[i] = p = p*3 % mod

    def rolling_hash(seq):
        h = sum([(i+1)*j for i, j in zip(seq, pow3[:-1])]) % mod
        H0s = [0]*n
        for i, j in enumerate(seq):
            H0s[i] = h
            h = (h-j-1+(j+1)*pn)*i3 % mod
        return H0s

    n = int(input())
    a, b = list(map(int, input().split())), list(map(int, input().split()))
    pn, memo = pow3[n], []

    a1 = [a[i-1] ^ a[i] for i in range(n)]
    b1 = [b[i-1] ^ b[i] for i in range(n)]
    b_hash = sum([(i+1)*j for i, j in zip(b1, pow3[:-1])]) % mod
    A1 = rolling_hash(a1)
    for i, j in enumerate(A1):
        if j == b_hash:
            memo.append(i)
    b0 = b[0]
    for i in memo:
        x = b0 ^ a[i]
        print(i, x)


main()
