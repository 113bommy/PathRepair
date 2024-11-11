import re
input_seq = input()
reverse_seq = input_seq[::-1]
mark = [0, 0]
seq_a = input()
seq_b = input()
reg = re.compile(seq_a + '.*' + seq_b)
if re.search(reg, input_seq):
	mark[0] = 1
if re.search(reg, reverse_seq):
	mark[1] = 1
if mark[0] == 0 and mark[1] == 0:
	print('fantasy')
elif mark[0] == 1 and mark[1] == 1:
	print('both')
elif mark[0] == 1:
	print('forward')
else:
	print('backward') 