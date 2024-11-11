n = int(input())
s = [int(i) for i in input().split()]
c = 0
b = 0
ba = 0

for i in range(0,n,3):
	c+=s[i]
for i in range(1,n,3):
	b+=s[i]

for i in range(2,n,3):
	ba+=1


if c>b and c>ba:
	print("chest")
elif b>ba and b>c :
	print("biceps")
else:
	print("back")
