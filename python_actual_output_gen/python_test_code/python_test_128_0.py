ABMR = list(map(int, input().split()))

print(ABMR)

a = ABMR[0]
b = ABMR[1]
m = ABMR[2]
r0 = ABMR[3]

h = {}
i = 0
prev_r = r0

while True:
    cur_r = ( a * prev_r + b ) % m
    # print(cur_r)
    if h.get(cur_r, 0) != 0:
        print(i - h[cur_r])
        break
    else:
        h[cur_r] = i
    prev_r = cur_r
    i += 1