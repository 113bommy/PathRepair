n,a,b = map(int,input().split())
tokens = [i for i in map(int,input().split())]
for i in tokens:
	print(i%b,end = ' ')