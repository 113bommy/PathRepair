# your code goes here
size, call_no = map(int, input().split())

list_val = [i for i in range(1,size+1)]

#print(list_val)




	
def modify(list_val,l,r):
	global count
	
	if count == call_no or r-l<2:
		return
	mid = (l+r)//2
	temp = list_val[mid]
	list_val[mid] = list_val[mid-1]
	list_val[mid-1] = temp
	count+=2
	modify(list_val,l,mid)
	modify(list_val,mid+1,r)


if call_no == 1:
	str_val = " ".join(str(x) for x in list_val)
	print(str_val)

elif call_no%2 == 0:
	print("-1")

else:
    count = 1
    modify(list_val,0,len(list_val)-1)
    if count < call_no:
        print("-1")
    else:
        print(" ".join(str(x) for x in list_val))
	
		