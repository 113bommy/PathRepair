a = {'monday':0,'tuesday':1,'wednesday':3,'thursday':4,'friday':5,'saturday':6,'sunday':7}

p = a[input()]
q = a[input()]

k = (q - p + 7)%7
if(k==0 or k==3 or k==2):
	print('YES')
else:
	print('NO')