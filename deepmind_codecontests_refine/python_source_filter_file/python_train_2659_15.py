nh = list(map(int, input().split()))
n = nh[0]
h = nh[1]
l = list(map(int, input().split()))
answer = 0
for a in l:
	if a>h:
		answer+=2
	else:
		answer+1
print(answer)