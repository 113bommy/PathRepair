def sieve(n):
	prime = [-1]*(n+1)
	for i in range(2,n+1):
		if prime[i]==-1:
			for j in range(i,n+1,i):
				prime[j] = i
	return prime

p = sieve(100010)
prime = []
for i in range(len(p)):
	if p[i]==i:
		prime.append(p[i])
# print (prime)
def find_prime(num):
	low = 0
	high = len(prime)-1
	while low<high:
		mid = (low+high)//2
		if prime[mid]<num:
			low = mid + 1
		else:
			high = mid - 1
	if prime[low]<=num:
		return prime[low]
	else:
		return prime[low-1]


def calc(ind):
	ans = []
	num = loc[arr[ind][0]]
	while num-ind>0:
		p = find_prime(num-ind+1)
		# print (p, num, ind)
		loc[a[num-p+1]], loc[a[num]] = loc[a[num]], loc[a[num-p+1]]
		a[num], a[num-p+1] = a[num-p+1], a[num]
		ans.append([num+1, num-p+2])
		num -= p-1
	return ans


n = int(input())
a = list(map(int,input().split()))
loc = {}
for i in range(n):
	loc[a[i]] = i
arr = []
for i in range(n):
	arr.append([a[i], i])
arr.sort()

i = 0
ans = []
while i<n:
	if arr[i][0]==a[i]:
		i += 1
		continue
	ans.extend(calc(i))
	i += 1
	# print (a)
	# print (loc)

print (len(ans))
for i in ans:
	print (*i)