inp = list(map(int, input().split()))
n = inp[0]

l = [0,2,3,4,4]

i = 5

count = 1
m = 0

while(i<=n):
	if(count == 1):
		l += [l[len(l)-1] +1]
		count +=1
		m  = int(l[len(l)-1]/2);
		if(i+m<n):
			# l  += [l[i]]*(m-1)
			i += (m-1)
			count = 1
		i+=1
		continue
	elif(count == m):
		l+= [l[len(l)-1]]
		count = 1;
		i+=1
		continue;
	else:		
		l += [l[len(l)-1]]
		count +=1

	i+=1
if(n < 5):
	print(l[n])
else:
	print(l[len(l)-1])