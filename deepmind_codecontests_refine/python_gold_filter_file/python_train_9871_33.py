import sys
input = sys.stdin.readline

N = int(input())
H = list(map(int,input().split()))
A = list(map(int,input().split()))

N += 1

# N: 処理する区間の長さ
N0 = 2**(N-1).bit_length()
INF = 2**31-1
data = [-INF]*(2*N0)
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
    s = -INF
    while L < R:
        if R & 1:
            R -= 1
            s = max(s, data[R-1])

        if L & 1:
            s = max(s, data[L-1])
            L += 1
        L >>= 1; R >>= 1
    return s

update(0,0)

for h,a in zip(H,A):
    update(h,query(0,h) + a)

ans = query(0,N+1)
print(ans)