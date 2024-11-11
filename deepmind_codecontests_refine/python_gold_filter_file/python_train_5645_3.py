def diff(a,b):
	ans = []
	for i in range(len(a)):
		ans.append(a[i]-b[i])
	return ans

a = input()
n = len(a)
q = int(input())
count = [[0 for i in range(26)] for j in range(n)]
count[0][ord(a[0])-97] += 1
for i in range(1,n):
	for j in range(26):
		count[i][j] = count[i-1][j]
	count[i][ord(a[i])-97] += 1

# for i in count:
	# print (*i)

for i in range(q):
	l,r = map(int,input().split())
	if l==r:
		print ("Yes")
	else:
		if a[l-1]!=a[r-1]:
			print ("Yes")
		else:
			d = diff(count[r-1],count[l-1])
			if d.count(0)<=23:
				print("Yes")
			else:
				print ("No")