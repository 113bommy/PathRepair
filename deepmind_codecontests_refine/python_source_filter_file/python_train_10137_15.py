n = input()
number = input()
ans = ""
while len(number)>4:
	ans = ans + number[:3] + '-'
	number = number[3:]
if len(number) == 4:
	ans = ans + number[:2] + '-' + number[:4]
else:
	ans = ans + number[:3]
print(ans)