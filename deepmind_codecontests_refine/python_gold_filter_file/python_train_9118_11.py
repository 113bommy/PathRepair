n = int(input())
num = str(input())
count = 0
answer = ''

for c in num:
	if c == '1':
		count += 1
	else:
		answer += str(count)
		count = 0

if count >= 0:
	answer += str(count)
print(answer)