Sum=0
p = []
n, k, m = map(int, input().split())
words = list(map(str, input().split()))
worth = list(map(int, input().split()))
for i in range(k):
	x = list(map(int, input().split()))
	if x[0]>1:
		x.pop(0)
		for bar in x:
			p.append(worth[int(bar)-1])
		y=min(p)
		for foo in x:
			worth[int(foo)-1]=y

dictionary=dict(zip(words, worth))
s=list(map(str, input().split()))
for a in s:
	Sum+=dictionary.get(a)
print(Sum)

