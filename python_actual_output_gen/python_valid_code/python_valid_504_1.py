'''
#
# 02.08.2021
#
# CF 736 B
#
'''

ttt_ = int (input ())

for __t in range (ttt_) :

	n = int (input ())
	tt = input ()
	s = input ()

	t = ['0']*n
	for i in range (n) :
		t [i] = tt [i]


	k = 0
	for i in range (n) :
		if s [i] == '1' :
			if t [i] == '0' :
				k += 1
			elif i > 0 and t [i-1] == '1' :
				k += 1
			elif i < n-1 and t [i+1] == '1' :
				k += 1; t [i+1] = '1'

	print (k)

# endfor __t
