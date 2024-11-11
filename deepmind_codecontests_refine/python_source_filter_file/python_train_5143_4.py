'''بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ'''
#codeforces
gi = lambda : list(map(int,input().split()))
a = gi()
d = {a[1] - a[0], a[2] - a[1], a[3] - a[2]}
if len(d) == 1:
	print(a[3] + a[3] - a[2])
	exit()
d = {a[1] / a[0], a[2] / a[1], a[3] / a[2]}
if len(d) == 1 and a[3] * (a[1] / a[0]) == int(a[3] * (a[1] / a[0])):
	print(a[3] * (a[1] / a[0]))
	exit()
print(42)