s = int(input().split()[1])
mugs = input().split()
total = 0
for i in range(len(mugs)):
    mugs[i]=int(mugs[i])
    total+=mugs[i]
total-=min(mugs)
if total>s:
    print("NO")
else:
    print("YES")
