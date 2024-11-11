n = int(input())
s = input()
acc_cnt_a = [0] * n
acc_cnt_b = [0] * n
acc_cnt_ab = [0] * n
c_loc = []
cnt_a = 0
cnt_b = 0
cnt_ab = 0
for i, c in enumerate(s):
    if c == 'D':
        cnt_a += 1
    elif c == 'M':
        cnt_b += 1
        cnt_ab += cnt_a
    elif c == 'C':
        c_loc.append(i)
    acc_cnt_a[i] = cnt_a
    acc_cnt_b[i] = cnt_b
    acc_cnt_ab[i] = cnt_ab

q = int(input())
buf = []
for k in map(int, input().split()):
    ans = 0
    for r in c_loc:
        l = r - k
        if l > 0:
            rejected_a = acc_cnt_a[l]
            cnt_internal_b = acc_cnt_b[r] - acc_cnt_b[l]
            cnt_internal_ab = acc_cnt_ab[r] - acc_cnt_ab[l]
            ans += cnt_internal_ab - rejected_a * cnt_internal_b
        else:
            ans += acc_cnt_ab[r]
    buf.append(ans)
print('\n'.join(map(str, buf)))
