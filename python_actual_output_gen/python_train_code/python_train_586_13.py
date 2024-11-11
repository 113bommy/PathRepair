S = input()
T = input()
T = T + T
index = T.find(S)
if S == -1:
	print("No")
else:
	print("Yes")