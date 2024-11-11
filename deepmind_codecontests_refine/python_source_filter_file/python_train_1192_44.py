Index=['q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/',' ']
n=input()
a=input()
if n=='R':
	for i in range(1,30):
		a=a.replace(Index[i],Index[i-1])
else:
	for i in range(29,0,-1):
		a=a.replace(Index[i],Index[i+1])
print(a)