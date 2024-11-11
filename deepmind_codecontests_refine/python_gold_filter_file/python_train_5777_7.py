a = int(input())
if a<=2:print(1);print(1)
elif a==3:print(2);print(1,3)
elif a==4:print(4);print(3,1,4,2)
else:
	print(a)
	for i in range(2,a+1,2):print(i,end=" ")
	for i in range(1,a+1,2):print(i,end=" ")
	print()