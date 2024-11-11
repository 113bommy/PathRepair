n = int(input())
e = [0] * (n-1)

# 素因数分解する  
for i in range(2, n+1):
    cur = i
    for j in range(2, i+1):
        # ひたすら割り算を繰り返す
        # 2で割り続ければ、4で割ろうとした時には2で割れない数になっている
        # 自動的に素因数分解ができる
        while cur % j == 0:
            e[j] += 1
            cur //= j

def num(m):
    return len([i for i in e if i >= m-1])

print(num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) \
      + num(5) * (num(5) - 1) * (num(3) - 2) // 2)