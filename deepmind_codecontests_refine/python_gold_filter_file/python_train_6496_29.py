m, n = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
c = 0
st = 1
for i in a:
    if i >= st: c += i - st
    else: c += m - st + i
    st = i
print(c)