n = int(input())
l = list(map(int, input().split()))
total = sum(l)
seats = l[0]
maj = total//2 + 1
ans = []
ans.append(1)
least = l[0]//2 + 1 if l[0]%2 == 1 else l[0]//2
i = 1;
flag = 0
while (seats < maj):
	if (i >= n):
		flag = 1
		break
	if (l[i] <= least):
		seats += l[i]
		ans.append(i+1)
	i+=1;

final = [str(x) for x in ans]
if (flag == 1 or seats < maj):
	print(0)
else:
	print(len(final))
	print(" ".join(final))