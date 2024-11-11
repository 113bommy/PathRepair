import sys
input = sys.stdin.readline
for nt in range(int(input())):
	n,r = map(int,input().split())
	a = list(map(int,input().split()))
	a = list(set(a))
	a.sort(reverse = True)
	count = 0
	for i in range(len(a)):
		a[i] -= count*r
		if a[i]<=0:
			break
		count += 1
	print (count)