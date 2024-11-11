n = int(input())

a = list(map(int, input().split()))

m = min(a)

cm, dis = 0,1000000
lm = a.index(min(a))

for i in range(lm+1, len(a)):
	if a[i]==m:
		if i-lm < dis:
			dis = i-lm
			lm = i
print (dis)