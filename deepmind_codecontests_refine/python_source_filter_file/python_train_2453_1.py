s = ["monday","tuesday","wednesday","thursday","friday","saturday","sunday","monday","tuesday","wednesday"]
a = input()
b = input()
cnt = 0
t=10**9
r = 10**9

for i in range(9):
	if s[i]==a:
		r=i
		for j in range(i,9):
			if s[j]==b:
				t=j
				break
		break


if abs(r-t)==0 or abs(r-t)==2 or abs(r-t)==3:
	print("YES")
else:
	print("NO")