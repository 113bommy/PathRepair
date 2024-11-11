s = str(input())
c = 'a'
min_num = 0

for i in s:
	x = ord(i) - ord(c)
	if x < 0:
		x = x + 26
	if x > 13:
		x = x - 26
	min_num = min_num + x
	c = i
	
print(min_num)