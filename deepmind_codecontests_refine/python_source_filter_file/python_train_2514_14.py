l = int(input())
n = input()
tab = list(map(int, input().split()))
md = ''
first = -1
end = -1
for i in range(l):
	if int(n[i]) < tab[int(n[i]) - 1]:
		first = i
		end = i
		k = end
		md = str(tab[int(n[i]) - 1])
		for j in range(k + 1, l):
			if int(n[j]) < tab[int(n[j]) - 1]:
				md += str(tab[int(n[j]) - 1])
				end += 1
			else:
				break
		break
if first == -1:
	print(n)
else:
	print(n[0:first] + md + n[end+1:])