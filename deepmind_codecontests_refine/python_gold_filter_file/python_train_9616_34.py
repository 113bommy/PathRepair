eve = []
odd = []
input()
c = 1
for i in input().split():
	eve.append(c) if int(i)&1==0 else odd.append(c)
	c += 1
print(eve[0]) if len(eve)==1 else print(odd[0])