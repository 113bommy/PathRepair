import sys
n = int(input())
parents = list(map(int, input().split()))
dict1 = {}
for i,j in enumerate(parents):
	if j in dict1:
		dict1[j].append(i+2)
	else:
		dict1[j] = [i+2]
s = list(map(int, input().split()))
dict2 = {}
dict3 = {}
dict2[1] = s[0]
dict3[1] = s[0]
for i,j in enumerate(s):
	if j != -1:
		dict2[i+1] = j
for i in range(2,n+1):
	if i not in dict2:
		p = parents[i-2]
		s = dict2[p]
		a = 0
		if i in dict1:
			a = 10**10
			for j in dict1[i]:
				if dict2[j] < s:
					print(-1)
					sys.exit()
				elif dict2[j] - s < a:
					a = dict2[j] - s 
		dict2[i] = a+s
		dict3[i] = a
	else:
		p = parents[i-2]
		s = dict2[p]
		if dict2[i] < s:
			print(-1)
			sys.exit()
		else:
			dict3[i] = s - dict2[i]
ans = 0
for i in dict3:
	ans += dict3[i]
print(ans)
			