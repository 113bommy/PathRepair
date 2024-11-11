N, *A = map(int, open(0).read().split())

v_max = max(A)
v_min = min(A)

flg1 = v_max > 0 and v_min > 0
flg2 = v_max <= 0 and v_min <= 0
flg3 = v_max * v_min < 0 and abs(v_max) >= abs(v_min)
flg4 = v_max * v_min < 0 and abs(v_max) < abs(v_min)

s = sorted([(i + 1, v) for i, v in enumerate(A)], key=lambda x: x[1])
ans = []
if flg1 or flg3:
    if flg3:
        i_max = s[-1][0]
        for j in range(1, N + 1):
            ans.append((i_max, j))
            
    for j in range(1, N):
        ans.append((j, j + 1))
else:
    if flg4:
        i_min = s[0][0]
        for j in range(1, N + 1):
            ans.append((i_min, j))
            
    for j in reversed(range(1, N + 1)):
        ans.append((j + 1, j))
        
print(len(ans))
for v in ans:
    print(*v)
