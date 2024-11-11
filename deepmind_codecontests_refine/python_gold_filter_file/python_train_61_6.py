s = input()
n = int(input())
l = list()
y = 0
for _ in range(n):
	l.append(input())
for i in l:
	if i[::-1]==s or i==s:
		print("YES")
		exit()
for i in l:
	if i[0]==s[1]:
		y+=1
		break
for i in l:
	if i[1]==s[0]:
		y+=1
		break
print("YES" if y==2 else "NO")