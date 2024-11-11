def solution(n,l):
	k = n-1
	j = k-1
	i = j-1
	l.sort()
	while i>=0:
		if l[i]+l[j]<l[k]:
			i -=1
			j -=1
			k -=1
		else:
			return True

	return False



n = int(input())
l = [int(x) for x in input().split(' ')]
print('YES' if solution(n,l) else 'NO')