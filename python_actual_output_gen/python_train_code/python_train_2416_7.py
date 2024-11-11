''' بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ '''
#codeforces1173A_live
gi = lambda : list(map(int,input().strip().split()))
x, y, z = gi()
if x - z > y:
	print("+")
	exit()
if y - z > x:
	print("-")
	exit()
if x == y and z == 0:
	print("0")
print("?")