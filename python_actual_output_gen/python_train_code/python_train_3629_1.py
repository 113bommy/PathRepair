l, r = input().split('|')
p = input()

ll = len(l)
lr = len(r)
lp = len(p)
mi = min(ll, lr)
ma = max(ll, lr)
if (ll + lr + lp) % 2 != 0 or mi + lp < ma or (mi == ma and mi > 0):
	print('Impossible')
else:
	if mi + lp == ma:
		if mi == ll:
			print(l + p +'|'+ r)
		else:
			print(l + '|' + r + p)
	else:
		q = (ll + lr + lp) // 2
		print(l + p[:q - ll] + '|' + r + p[q - ll:])