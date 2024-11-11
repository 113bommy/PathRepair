# import sys
# sys.stdin=open('F:\\C\\Script\\input.txt','r')
# sys.stdout=open('F:\\C\\Script\\output.txt','w')
# sys.stdout.flush()

I = lambda:list(map(int,input().split()))
MOD = 1000000007
n,m = I()
l = I()
count = 0 
pages = 0
i = 0
while i < n:
	count = 0
	pages += l[i]
	if pages >= m:
		count += pages//m
		pages = pages - pages//m
	print (count,end = ' ')
	i += 1
