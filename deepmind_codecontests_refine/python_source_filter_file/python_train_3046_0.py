from sys import stdin,stdout
 
# stdin = open("input.txt","r")
# stdout = open("output.txt","w")
 
t = int(stdin.readline().strip())
 
for _ in range(t):
	n,k = stdin.readline().strip().split(' ')
	n,k = int(n),int(k)
 
	arr = list(map(int,stdin.readline().strip().split(' ')))

	d={}
	for i in arr:
		key = (k-(i%k))%k
		if key in d:
			d[key]+=1
		else:
			d[key]=1
	m=0;ind=0
	# print(d)
	for i in d:
		if i!=0:
			if d[i]>m:
				m=d[i];
			if d[i]==m:
				if i>ind:
					ind = i
	# print(m,ind)
	if m==0 and ind==0:
		ans=0
	else:
		ans=(m-1)*k + ind + 1
	stdout.write(str(ans)+"\n");
