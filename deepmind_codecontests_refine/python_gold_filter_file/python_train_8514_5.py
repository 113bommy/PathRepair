import sys

s = input()
t = input()
s_len = len(s)
t_len = len(t)
index_list = [0]*t_len
rt1 = 0
rt2 = 0
s = s + s
for m in range(t_len):
	rt1 = s.find(t[m],rt1)
	if rt1 == -1:
		print(rt1)
		sys.exit()
	else:
		#rt1 = rt1 % s_len + 1
		#index_list[m] = rt1
		if rt1 < s_len:
			pass
		else:
			rt1 = rt1 % s_len
			rt2 += 1
	rt1 += 1
rt = rt1 + rt2 * s_len
print(rt)