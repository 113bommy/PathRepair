from bisect import bisect_right
s=input()
t=input()
dic={}
n=len(s)
for i in range(n):
	if s[i] in dic:
		dic[s[i]].append(i)
	else:
		dic[s[i]]=[i]
k=-1
r=0
for i in t:
	if i in dic:
		a=bisect_right(dic[i],k)
		if a==len(dic[i]):
			r+=1
			k=dic[i][0]
		else:
			k=dic[i][a]
	else:
		print(-1)
		exit()
print(r*n+k+1)
