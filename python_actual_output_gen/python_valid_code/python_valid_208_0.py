n = int(input())
As = list(map(float, input().split()))

B = list(x - int(x) for x in As if x - int(x) > 0.000)
l = len(B)
if l == 0:
	print('{:.3f}'.format(0))
	exit(0)

S = sum(x for x in B)

print(S)

ll = l if l % 2 == 0 else l + 1
ans = 1e10
for i in range(max(0, l - n), (n if l > n else l) + 1):
	ans = min(ans, abs(i - S))

print('{:.3f}'.format(ans))
