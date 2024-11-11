def ch(a):
    cnt = 0
    while a > 0:
        a //= 10
        cnt += 1
    return cnt
a = int(input())
b = list(map(int,input().split()))
k = [0] * 20
for i in range(a):
    k[ch(b[i])] += 1
summ = 0
summ1 = 0
st = [1]
for i in range(22):
    st.append(st[-1] * 10)
for i in range(a):
    ot = [b[i] * 10, b[i] // 10 * 100 + b[i] % 10]
    for j in range(2, 22):
        if j % 2 == 0:
            ot.append(ot[-1] * 10)
            continue
        n = ot[j - 2]
        ot.append(n // st[j] * st[j + 1] + n % st[j])
    l = ch(b[i])
    for j in range(0, 10):
        if l == j:
            summ1 += (k[j]) * (ot[j * 2 - 2] + ot[j * 2 - 1])
        else:
            summ += k[j] * (ot[j * 2 - 2] + ot[j * 2 - 1])
    #print(summ, summ1)
    print(*ot)
print((summ + summ1) % 998244353)