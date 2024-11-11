N, K = map(int, input().split())

lm = 300001

# N: 処理する区間の長さ
N0 = 2**(lm-1).bit_length()
INF = 0
data = [INF]*(2*N0)
# a_k の値を x に更新
def update(k, x):
    k += N0-1
    data[k] = x
    while k >= 0:
        k = (k - 1) // 2
        data[k] = max(data[2*k+1], data[2*k+2])
# 区間[l, r)の最小値
def query(l, r):
    L = l + N0; R = r + N0
    s = 0
    while L < R:
        if R & 1:
            R -= 1
            s = max(s, data[R-1])

        if L & 1:
            s = max(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s

for _ in range(N):
    a = int(input())
    x = query(max(0, a-K), min(lm, a+K+1))
    update(a, x+1)

print(query(0, N))