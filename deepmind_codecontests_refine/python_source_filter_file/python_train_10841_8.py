import sys
n = int(input())
x = [int(x) for x in input().split()]

l = 0
r = n-1
ldiff = -sys.maxsize -1
rdiff = -sys.maxsize -1
while l<r:
	if x[l] != x[r]:
		ldiff = r-l
		break
	else:
		l+=1
l = 0
r = n-1
while l<r:
	if x[l] != x[r]:
		ldiff = r-l
		break;
	else:
		r-=1

print(max(ldiff,rdiff))
