n = int(input())
st, sh = 0, 0
for i in range(n):
    t, h = map(str, input().split())
    if t > h:
        st += 3
    elif t < h:
        sh += 3
    else:
        st += 1
        st += 1
print(st, sh)