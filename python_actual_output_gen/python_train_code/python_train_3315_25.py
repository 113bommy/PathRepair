n = int(input())
a = [int(i) for i in input().split()]

def pick(a):
	for i in range(len(a)-2):
		if (a[i]%2!=a[i+1]%2):
			if(a[i+1]%2!=a[i+2]):
				return i+1+1
			else:
				return i+1
	return len(a)

print(pick(a))
