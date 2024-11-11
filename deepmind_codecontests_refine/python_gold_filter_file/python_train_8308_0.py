n = int(input())
Ps = [int(input())for _ in range(n)]
p_to_i = {p: i for i, p in enumerate(Ps)}

cnt = x = 1
for p in range(1, n):
    if p_to_i[p] < p_to_i[p+1]:
        x += 1
        if cnt < x:
            cnt = x
    else:
        x = 1
print(n-cnt)
