from collections import defaultdict

def find(x):
	if len(li)==1:
		return -1
	if len(li) ==2 and li[0] == li[1]:
		return 2
	ans = float('inf')
	dic = {}
	i = 0
	j = 0
	
	while i<len(li) and j<len(li):
		if li[i] in dic:
			index = dic[li[i]] 
			ans = min(ans,i-index + 1)
			dic[li[i]] = i
		else:
			dic[li[i]] = i
		i+=1
	if ans == 'inf':
		return -1
	return ans
	
for i in range(int(input())):
	x = input()
	li = list(map(int,input().split()))
	ans = find(li)
	print(ans)
	
