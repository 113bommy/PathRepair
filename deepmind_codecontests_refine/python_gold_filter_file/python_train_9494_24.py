
import math
t=int(input())

for i in range(t):
	n=int(input())
	a, b, c= list(map(int, input().split()))
	req={'R':0, 'P':0, 'S':0}
	move={'R':'P', 'P':'S', 'S':'R'}
	d={}
	use={}
	d['R']=a
	d['P']=b
	d['S']=c
	win=0
	s=input()

	for c in s:
		req[move[c]]+=1
	for i in 'RPS':
		use[i]= min(d[i], req[i])
		win+=use[i]
	if (win>=math.ceil(n/2)):

		print("YES")
		res=''
		for c in s:
			if d[move[c]]>0:
				use[move[c]]-=1
				d[move[c]]-=1
				res+=move[c]
			else:
				for i in "RPS":
					if(d[i]-use[i]>0):
						d[i]-=1
						res+=i
						break
		print(res)





	else:
		print("NO")

