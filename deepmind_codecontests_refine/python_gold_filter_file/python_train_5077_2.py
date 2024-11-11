n,B = map(int,input().split())
s = [int(i) for i in input().split()]
r=[]
even = int(s[0]%2==0)
odd = int(s[0]%2!=0)
ans = 0
cnt = 0
count= 0
for i in range(1,n-1):
	if s[i]%2==0:
		even+=1
	else:
		odd+=1
	a = abs(s[i]-s[i+1])
	if odd == even:
		r.append(a)
r.sort()

for i in range(len(r)):
	if cnt+r[i]>B:
		ans = count
		break
	count+=1
	cnt+=r[i]

print(max(ans,count))