n = int(input().strip())
a= [int(_) for _ in input().strip().split()]
count=0
while (round(sum(a)/n+ 0.01))!= 5:
	count+=1
	a[a.index(min(a))]= 5
print(count)