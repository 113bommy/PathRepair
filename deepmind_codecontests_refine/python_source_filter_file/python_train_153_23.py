#-*- coding:utf-8 -*-
#!/usr/bin/python3

import sys
person = 0
ans = 0

for st in sys.stdin:
	if st[0] == '+':
		person += 1
	elif st[0] == '-':
		person -= 1
	else:
		ans += person * (len(st) - st.find(':') - 1)
print(ans)
