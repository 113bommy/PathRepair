zodis=input()
n=int(input())
t=set(zodis)
if n>len(zodis):
	print("impossible")
else:
	print(max(0,n-len(t)))