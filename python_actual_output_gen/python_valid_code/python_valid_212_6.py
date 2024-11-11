num_digits = int(input())

digits = list(input())

result=''
result_list=[None,None,2,3,322,5,63,7,7222,7332]



for i in digits:
	
	if i!='0' and i!='1':
	    result+= str(result_list[int(i)])
		
print(int(''.join(sorted(list(result),reverse=True))))
		
