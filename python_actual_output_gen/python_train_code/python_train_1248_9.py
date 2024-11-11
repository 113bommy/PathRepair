n = int(input())
a = list(map(int,input().split()))
x = sum(a) // 2
day , now= 1, 0
for i in a:
	now += i
	if(x <= now):
		break
	day += 1
print(day)