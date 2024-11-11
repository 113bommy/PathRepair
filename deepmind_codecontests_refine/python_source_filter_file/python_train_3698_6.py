t = input()
d = input()
r = d.count('R')
g = d.count('G')
b = d.count('B')	
if (r>0 and g>0 and b>0):
	print('BGR')
	exit(0);
if (r==0 and g==0):
	print('B')
	exit(0)
if (r==0 and b==0):
	print('G')
	exit(0)
if (b==0 and g==0):
	print('R')
	exit(0)
if (b==1 and r ==1):
	print ('G')
	exit(0)
if (b==1 and g ==1):
	print ('R')
	exit(0)
if (r==1 and g ==1):
	print ('B')
	exit(0)
if (b>1 and r ==1):
	print ('GR')
	exit(0)
if (b>1 and g ==1):
	print ('GR')
	exit(0)
if (r>1 and g ==1):
	print ('BG')
	exit(0)
if (r>1 and b ==1):
	print ('BG')
	exit(0)
if (g>1 and b ==1):
	print ('BR')
	exit(0)
if (g>1 and r ==1):
	print ('BR')
	exit(0)
print('RGB')