a = input()
b = input()

def dividir_para_conquistar(c):
	s_size = len(c)
	
	if(s_size == 1):
		return c
	
	s1 = dividir_para_conquistar(c[0 : int(s_size / 2)])
	s2 = dividir_para_conquistar(c[int(s_size / 2) : s_size])
	
	if(s1 < s2):
		return s1 + s2
	
	return s2 + s1
	
a = dividir_para_conquistar(a)
b = dividir_para_conquistar(b)

if(a == b):
	print("YES")
else:
	print("NO")