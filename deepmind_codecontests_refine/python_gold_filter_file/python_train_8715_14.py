d={"purple":'Power','green':'Time','blue':'Space','orange':'Soul','red':'Reality','yellow':'Mind'}
x=int(input())
if x>0:
	for i in range(1,x+1):
		y=input()
		if y in d:
			d.pop(y)

print(6-x)
for i in d.values():
	print(i)