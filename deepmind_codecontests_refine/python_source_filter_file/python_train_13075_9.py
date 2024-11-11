n, m = map(int, input().split())
s = input()
t = input()
ans = float("+inf")
l = list()

for i in range(m-n+1):
    j = 0
    temp = 0
    t_l = []
    while j < n:
        if s[j] == t[j+i]:
            temp += 1
        else:
            t_l.append(j+i+1)
        j += 1
    if ans > n-temp:
        ans = n-temp
        l = t_l
print(ans)
print(*l)
