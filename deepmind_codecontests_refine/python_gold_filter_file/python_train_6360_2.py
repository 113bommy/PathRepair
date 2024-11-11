n=int(input())
a, b = input(), input()
ans = 0
aa = 0
bb = 0
for i in range(n):
	if b[i]=='1':
		if a[i]=='1':
			aa+=1
	if a[i]=='0':
		bb+=1

for i in range(n):
	if b[i]=='0':
		if a[i]=='0':
			ans +=aa
		else:
			ans+=bb
print(ans)
			
		