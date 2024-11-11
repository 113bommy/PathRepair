n = int(input()); l = input(); k = ['0']*(10)
h=0;
while h<n:
	f=0
	if l[h]=='L':
		for f in range(10):
			if k[f]== '0': k[f]='1'; break
	elif l[h]=='R':
		for f in range(9,0,-1):
			if k[f]== '0': k[f]='1'; break
	else:
		k[int(l[h])]='0'
	h+=1
print(''.join(k))