def f(a,b):
	return (a+b)*(b-a+1)//2
n,m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.append(10**9+1)
temp = 0
count = 0
for j in range (n+1):
	if( (temp+1) != a[j]):
		if(m>=f(temp+1, a[j]-1)):
			count += a[j]-temp-1
			m = m - f(temp+1,a[j]-1)
		else:
			i = temp + 1
			while m >= i:
				m = m - i
				i += 1
				count += 1
			break
	temp = a[j]
print (count)
temp = 0
for j in range (n+1):
	if(count <= 0):
		break
	else:
		if( (temp+1) != a[j]):
			for i in range (temp+1, a[j]):
				if(count > 0):
					print (i, end = ' ')
					count -= 1
				else:
					break
		temp = a[j]
			