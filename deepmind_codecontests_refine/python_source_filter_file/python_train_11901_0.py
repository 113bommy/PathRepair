# from math import sqrt
# def ispronic(num):
# 	if num%2!=0 or num==0:
# 		return False
# 	x = sqrt(4*num+1)
# 	if x==int(x):
# 		return True
# 	return False

# s = input()
# l = []
# for i in range(len(s)):
# 	sub = ''
# 	for j in range(i,len(s)):
# 		sub = sub+s[j]
# 		l.append(int(sub))
# # print(l)
# ans = set()
# for i in range(len(l)):
# 	if ispronic(l[i]):
# 		ans.add(l[i])
# ans = list(ans)
# print(sorted(ans))
from collections import defaultdict
n,q = map(int,input().split())
a = list(map(int,input().split()))
qarr = list(map(int,input().split()))
d = defaultdict(lambda:0)
for i in range(n):
	if d[a[i]]==0:	
		d[a[i]] = i+1

for i in range(q):
	k = d[qarr[i]]

	for j in range(50):
		if d[j]!=0 and d[j]<k:
			d[j]+=1
	d[qarr[i]] = 1
	print(k,end=' ')
print()
