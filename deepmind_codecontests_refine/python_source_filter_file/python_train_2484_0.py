N = int(input())
A = [int(input()) for i in range(N)]


# 全体のxorを計算
XOR = 0
for a in A:
    XOR ^= a


ans = 0
for i in reversed(range(30)):
    if not ((1 << i) & XOR):
        continue

    for j, a in enumerate(A):
        a_bit = bin(a)[2:].zfill(30)
        if a_bit[30 - i - 1:] == '1' + '0' * i:
            ans += 1
            XOR ^= a
            XOR ^= (a - 1)
            A[j] -= 1
            break
    else:
        print(-1)
        exit()

print(ans)
