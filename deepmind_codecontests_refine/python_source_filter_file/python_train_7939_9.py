n = int(input())
a = sorted(list(map(int, input().split())))
val = 0
b, c = a[:n//2], a[n//2:-1]
sol = [a[-1]]
d = []
b_ptr, c_ptr = len(b)-1, len(c)-1
while True:
    if b_ptr<0 or c_ptr<0:break
    cc = c[c_ptr]
    while b_ptr>=0:
        if b[b_ptr]>=cc:
            d.append(b[b_ptr])
            b_ptr-=1
        else:
            break
    if b_ptr<0:
        break
    else:
        sol.append(b[b_ptr])
        b_ptr-=1
        sol.append(c[c_ptr])
        c_ptr-=1
        val+=1

sol += b[:max(b_ptr, 0)]+c[:max(c_ptr, 0)]+d
print(val)
print(' '.join([str(i) for i in sol]))