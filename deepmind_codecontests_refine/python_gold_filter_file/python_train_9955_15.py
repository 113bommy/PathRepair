d = {"Danil","Olya","Slava","Nikita","Ann"}
cnt = 0
n = input()
for i in d:
	cnt += n.count(i)

if cnt==1:
	print("YES")
else:
	print("NO")