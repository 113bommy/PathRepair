zodis=input()
n=int(input())
t=set(zodis)
if n>len(zodis):
	print("Impossible")
else:
	print(n-len(t))