no = int(input())

x=list(map(int,input().split()))

chest=0
bicep=0
back=0

for i in range(0,no,3):
	chest+=x[i]

for i in range(1,no,3):
	bicep+=x[i]
	
for i in range(2,no,3):
	back+=x[i]
	
	
if((chest>bicep and chest>back)):
	print("chest")
elif((bicep>chest and bicep>back)):
	print("bicep")
elif((back>chest and back>bicep)):
	print("back")