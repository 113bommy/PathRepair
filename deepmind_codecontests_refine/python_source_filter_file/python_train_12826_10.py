import sys
n, k = map(int,input().split())
def guess(arr):
	print(*(["?"]+arr))
	sys.stdout.flush()
	pos, val = map(int,input().split())
	return val

odp = ["chuj"]
for i in range(1, k + 2):
	lis = list(range(1,k + 2))
	lis.pop(i - 1)
	new = guess(lis)
	odp.append(new)
x = min(odp[1:])
print(odp.count(x))