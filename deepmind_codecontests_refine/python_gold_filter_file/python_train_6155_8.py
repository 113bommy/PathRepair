n=int(input())
x,y=map(int,input().split())
z=min(x,y)
k=max(x,y)
w=z-1
b=n-k
if w<=b:
	print("White")
else:
	print("Black")