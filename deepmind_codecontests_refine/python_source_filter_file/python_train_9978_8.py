N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7

# 重複している要素Xを探す
X_search_set = set()
for a in A:
    if a in X_search_set:
        X = a
        break
    else:
        X_search_set.add(a)

# 重複している要素のindexを取得
x_left, x_right = [i for i, a in enumerate(A) if a == X]

# 重複している要素の左側・右側にそれぞれ何個あるか
Left, Right = x_left, N - x_right

# 階乗 & 逆元計算
factorial = [1]
inverse = [1]
for i in range(1, N+2):
    factorial.append(factorial[-1] * i % mod)
    inverse.append(pow(factorial[-1], mod-2, mod))


# 組み合わせ計算
def nCr(n, r):
    if n < r or r < 0:
        return 0
    elif r == 0:
        return 1
    return factorial[n] * inverse[r] * inverse[n - r] % mod


# 計算・出力
for k in range(1, len(A) + 1):
    ans = nCr(len(A), k)

    # 重複部分を引く
    if k - 1 <= Left + Right:
        ans -= nCr(Left + Right, k - 1)

    print(ans)
