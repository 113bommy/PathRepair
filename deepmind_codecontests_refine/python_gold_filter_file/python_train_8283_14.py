a = []
for i in range(4):
	a.append(int(input()))

b = ""
for i in a:
	b += str(i)
	
num = int(b, 2)
ans = [0 for x in range(16)]
ans[0] = 0 #
ans[1] = 1 #
ans[2] = 0 #
ans[3] = 1 #
ans[4] = 0 #
ans[5] = 0 #
ans[6] = 0 #
ans[7] = 0 #
ans[8] = 1 #
ans[9] = 1 #
ans[10] = 0 #
ans[11] = 1 #
ans[12] = 1 #
ans[13] = 0
ans[14] = 1 #
ans[15] = 1
print(ans[num])