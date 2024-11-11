n = input()
flag1, flag2, flag3, flag4 = 0, 0, 0, 0
if len(n)>=5:
	flag1 = 1
for i in n:
	if i.isdigit():
		flag2 = 1
	if i.swapcase().isupper():
		flag3 = 1
	if i.swapcase().islower():
		flag4 = 1
if flag1 and flag2 and flag3 and flag4:
	print('Correct')
else:
	print('Too Weak')