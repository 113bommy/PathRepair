t = input()
flag = 0
d = {}
l = ["ACB","BAC","CAB","ABC","BCA","CAB","CBA"]
for i in range(len(t)-2):
	if t[i:i+3] in l:
		flag = 1
		print("YES")
		break
if flag == 0:
	print("NO")
