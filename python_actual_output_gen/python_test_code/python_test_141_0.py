n = int(input())
k = input()

a = ""

ans = 0
base = 0
i = len(k) - 1
while i >= 0:
    p_a = a
    a = k[i] + a
    i -= 1
    a_i = int(a)
    #print(p_a, a)
    if (a_i > n):
        i += 1
        a = p_a
        while (len(a) > 1 and a[0] == '0'):
            a = a[1:]
            i += 1
        ans += int(a) * n ** base
        a = ""
        base += 1
ans += int(a) * n ** base
print(ans)