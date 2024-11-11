t = int(input())

def scob(n, o, c, str):
	global cnt
	if cnt==n:
		return
	if (o==n and c==n):
		cnt += 1 
		print(str)
	if(o<n):
		str += "("
		scob(n, o+1, c, str)
		str = str[:-1]
	if(o<=n and c<o):
		str += ")"
		scob(n, o, c+1, str)
		str = str[:-1]
		
for _ in range(t):
	n = int(input())
	cnt = 0
	scob(n, 0, 0, "")
	