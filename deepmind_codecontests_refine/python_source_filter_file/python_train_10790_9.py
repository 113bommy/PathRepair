l, r, a = map(int, input().split())
ans = 0
for i in range(1, 100):
    nr = r - i
    nl = l - i
    na = a + 0
    if (nl < 0):
        na += nl
    if (nr < 0):
        na += nr
    if (na >= 0):
        ans = i + 0
print(ans * 2)