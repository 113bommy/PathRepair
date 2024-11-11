n,k = map(int, input().split())

list_a = list(map(int,input().split()))
list_b = list(map(int,input().split()))

len_a = len(list_a)
len_b = len(list_b)

if(len_b>1):
	print("Yes")
	exit(0)

else:
	replace_index = list_a.index(0,0,len_a-1)
	list_a[replace_index] = list_b[0]

	for i in range(0,len_a-2):
		if(list_a[i] < list_a[i+1]):
			print("Yes")
			exit(0)

print("No")





	