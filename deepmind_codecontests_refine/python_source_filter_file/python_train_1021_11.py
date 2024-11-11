H, W = map(int, input().split())
s_list = [input() for i in range(H)]
flag = False

for i in range(1, H - 1):
	for j in range(1, W - 1):
		if s_list[i][j] == "#":
			if s_list[i-1][j] == "." and s_list[i+1][j] == "." and s_list[i][j-1] == "." and s_list[i][j+1] == ".":
				flag = True
				break
if flag:
	print("Yes")
else:
	print("No")