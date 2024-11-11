N, H = map(int, input().split())
B = []
a_max = 0
for i in range(N):
    a, b = map(int, input().split())
    a_max = max(a_max, a)
    B.append(b)

B = sorted([b for b in B if b > a_max], reverse = True)

cnt = 0
for b in B:
    H -= b
    cnt += 1
    if H <= 0:
	break
if H > 0:
    cnt += ((H-1) // a_max) + 1


print(cnt)
