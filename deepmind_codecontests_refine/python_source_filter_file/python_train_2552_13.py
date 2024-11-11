n = input()
li = list(map(int,input().split()))
li = sorted(li)
li = li[::-1]
sum=0
a=max(li)
for i in li:
	if a<0:
		break
	sum+=min(a,i)
	a=i
	a-=1
print(sum)	