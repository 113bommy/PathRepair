lst = [int(x) for x in input().split()]
days = [0,1,2,0,2,1,0]
weeks = min(lst[0]//3,lst[1]//2,lst[2]//2)
lst[0] -= 3*weeks
lst[1] -= 2*weeks
lst[2] -= 2*weeks
ans = weeks*7
add = 0 
for i in range(7):
	tmp = lst
	curr = 0
	for j in range(7):
		day = days[(i+j)%7]
		tmp[day] -= 1
		if tmp[day] < 0:
			break
		curr += 1
	add = max(add,curr)
ans += add
print(ans)