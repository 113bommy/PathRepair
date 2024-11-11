def bin(s):
	a=s.count('n')
	b=s.count('z')
	str='1'*a+'0'*b
	return int(str)
	
n=input()
s=input()	
print(bin(s))