# import sys
# sys.stdin=open('F:\\C\\Script\\input.txt','r')
# sys.stdout=open('F:\\C\\Script\\output.txt','w')
# sys.stdout.flush()

I = lambda:list(map(int,input().split()))

n , =I()
s = input()
t = input()

if sorted(s) == sorted(t):
	temp = s
	b = []
	for i in range(n-1):
		if t[i] != temp[i]:
			k = temp[i:].find(t[i]) + i
			for l in range(k - 1 , i - 1,-1):
				b.append(l)
			temp = t[:i+1] + s[i:k] + s[k+1:] 
	print (len(b))
	for i in b:
		print(i+1,end = " ") 
else:
	print (-1)