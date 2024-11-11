s = list(map(str,input()))
c = list(map(str,input()))
n = len(s)

s.sort()
c.sort(reverse = True)

s = s[:(n+1)//2]
c = c[:n//2]
l_s = len(s)
l_c = len(c)
begin_s = 0
begin_c = 0
end_s = l_s-1
end_c = l_c-1
ans1 = []
ans2 = []

for i in range(n-1):
    if i%2 == 0:
        if s[begin_s] >= c[begin_c]:
            ans2.append(s[end_s])
            end_s -= 1
        else:
            ans1.append(s[begin_s])
            begin_s += 1
    else:
        if c[begin_c] <= s[begin_s]:
            ans2.append(c[end_c])
            end_c -= 1
        else:
            ans1.append(c[begin_c])
            begin_c += 1
if n%2:
    ans1.append(s[begin_s])
else:
    ans1.append(c[begin_c])

print(*ans1+list(reversed(ans2)),sep='')
