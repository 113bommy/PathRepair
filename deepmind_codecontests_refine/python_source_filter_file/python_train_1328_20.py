W,Y=map(int,input().split())
K=max(W,Y)
S=7-K
if (S==1 or S==5):
	print(str(S)+"/6")
elif (S==2 or S==4):
	print(str(S//2)+"/3")
elif (S==3):
	print(str(S//3)+"/2")
else:
	print(1)