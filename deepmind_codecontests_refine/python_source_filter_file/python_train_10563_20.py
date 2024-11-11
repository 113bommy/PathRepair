
lang={}		
n,m=map(int,input().split())
for i in range(m):
	arr=list(map(str,input().split()))
	lang.update({arr[0]:arr[1]})
str1=list(map(str,input().split()))
# print(*lang.values())
# print(str1)
for i in range(n):
	if str1[i] in lang:
		x=str1[i]
		y=lang[x]
		if len(x)<len(y):
			print(x,end=' ')
		else:print(y,end=' ')
	else:
		y=str1[i]
		for k in lang:
			if lang[k]==y:
				x=lang[k]
				break
			else:continue
		if len(x)<len(y):
			print(x,end=' ')
		else:print(y,end=' ')




