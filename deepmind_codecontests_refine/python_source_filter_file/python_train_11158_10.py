n = int(input())
s = input()
t = input()
# 'abcabcabc' -> ab,bc,ca
s1 = {'ab','bc','ca'}
# 'bacbacbac' -> ba,ac,cb
s2 = {'ba','ac','cb'}
s1n = s1 - {s,t}
s2n = s2 - {s,t}
if(len(s1n)==3):
	print('YES')
	print('abc'*n)
elif(len(s2n)==3):
	print('YES')
	print('bac'*n)
else:
	print('YES')
	ss1 = 'bca' if (s=='ab' or t=='ab') else ('abc' if (s=='ca' or t=='ca') else 'cab')
	print(ss1[0]*n+ss1[1]*3+ss1[2]*3)