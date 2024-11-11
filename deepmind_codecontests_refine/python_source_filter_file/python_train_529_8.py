[n, L, a] = input().split(" ")[:3]
[n, L, a] = [int(n), int(L), int(a)]
fL = L
t_im = 0
l_im = 0
TotalBreakTime = 0
if n == 0:
    TotalBreakTime = int(n / a)
for i in range(n):
    [ti, li] = input().split(" ")[:2]
    [ti, li] = [int(ti), int(li)]
    if i == 0:
        t_im = 0
        l_im = 0
    if (ti - t_im - l_im >= a):
        TotalBreakTime += int((ti - t_im - l_im) / a)
    l_im = li
    t_im = ti
    if i == n-1:
        if (fL - ti - li) >= a:
            TotalBreakTime += int((fL - ti - li) / a)
print(TotalBreakTime)
