n = int(input())
s = input()
ok = False
for i in range(n):
	if i > 0 and s[i - 1] > s[i]:
		ok = True
		ans = i
		break

if ok:
	print("YES")
	print("%d %d" %(ans - 1 , ans))
else:
	print("NO")
