k = 0
x = int(input())
a = list(map(int,input().split()))
r = max(a)
while k < sum(a):
	k = (r*len(a)-sum(a))
	r = r + 1
print(r-1)