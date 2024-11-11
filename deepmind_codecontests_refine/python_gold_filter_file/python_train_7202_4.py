import bisect
x, y = map(int, input().split())

i = 2
l = [4, 7]
while(l[-1] <= 10**11):
	if(i%2 == 0):
		l.append(l[(i-1)//2]*10 + 4)
	else:
		l.append(l[(i-1)//2 - 1]*10 + 7)
	
	i += 1

val1 = bisect.bisect_left(l, x, 0, len(l))
val2 = bisect.bisect_right(l, y, 0, len(l))

start = 0
for i in range(len(l)):
	if(l[i] == l[val1]):
		start = i
		break
#print("Start ", start)
ans = (min(l[val1], y) - x + 1)*l[val1]
#print("Initial ans", ans)
#print(val1, val2)
#print(l[val1])
for i in range(start + 1, len(l)):
	if(l[i] <= l[val2]):
		ans += l[i]*(min(y, l[i]) - l[i-1])
	else:
		break
	
	#print("Temp", ans)
print(ans)