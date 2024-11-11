def lcm(a,b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return (a+b)
t, w, b = map(int, input().split())
lcm_wb = (w*b)//lcm(w,b)
count = t//lcm_wb
min_wb = min(w, b)
ans = min_wb*(count-1)+min_wb+min((t-lcm_wb*(count)), min_wb)-1
gcb_anst = lcm(t,ans)
print(ans//gcb_anst, '/', t//gcb_anst, sep = '')
