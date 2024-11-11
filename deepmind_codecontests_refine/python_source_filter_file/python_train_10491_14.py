n, k = (int(x) for x in input().split())
A = list(int(x) for x in input().split())
MOD = 10**9 + 7
A.sort()

l = 0
r = n - 1
flag = False  # マイナスになってしまうかフラグ
ans = 1
if k % 2 == 1:
    ans = A[r]
    r -= 1
    k -= 1
    if ans < 0:
        sign = True


if flag:  # どうしてもマイナスになってしまう場合(kが奇数で要素すべてがマイナスの場合)
    while k:
        ans *= A[r] * A[r - 1] % MOD
        ans %= MOD
        r -= 2
        k -= 2
else:  # 必ず0以上にできる場合
    while k:
        x = A[l] * A[l + 1]
        y = A[r] * A[r - 1]
        if x > y:
            ans *= x % MOD
            ans %= MOD
            l += 2
        else:
            ans *= y % MOD
            ans %= MOD
            r -= 2
        k -= 2

print(ans)
