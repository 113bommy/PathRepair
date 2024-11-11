
def f(n, a):
    x = sorted(set(a))
    n_sub_half = (n * (n + 1)) // 2 // 2
    n1 = n * 2 + 1
    li = 0
    ri = len(x)
    while ri > li + 1:
        i = (li + ri) // 2
        xi = x[i]
        cnt = [0] * n1
        cs = 0
        cnt[cs] = 1
        judge = 0
        s = 0
        for ak in a:
            if ak >= xi:
                cs += 1
                s += cnt[cs] + 1
            else:
                cs -= 1
                s -= cnt[cs + 1] - 1
            cnt[cs] += 1
            judge += s
            if judge >= n_sub_half:
                li = i
                break
        else:
            ri = i
    return x[li]

n = int(input())
ar = [int(i) for i in input().strip().split(" ")]
print(f(n,ar))



