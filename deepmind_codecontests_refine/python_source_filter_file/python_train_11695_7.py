"""

Author	:	Indian Coder
Date	:	29th May ,2021

"""
#Imports

import math
import time 
import random
start=time.time()


n=int(input())
sample=0
sample1=[]
for i in range(0,n):
	a1=list(map(int ,input().split()))
	sample+=(sum(a1))
	sample1.append(a1)
if(n<=3):
	print(sample)
else:
	back_val=n
	back_value_list=[]
	for i in range(0,len(sample1)):
		back_value_list.append(sample1[i][back_val-1])
		back_val-=1
	#print(sample1)
	#print(back_value_list)
	front_valu=0
	front_value_list=[]
	for j in range(0,len(sample1)):
		front_value_list.append(sample1[j][front_valu])
		front_valu+=1
	#print(front_value_list)
	
	middle_col_value=0
	pos_add=n//2+1
	for k in range(0,len(sample1)):
		middle_col_value+=sample1[k][pos_add-1]
	#print(middle_col_value)
	
	middle_row_sum=sum(sample1[pos_add-1])
	
	print(sum(front_value_list)+sum(back_value_list)+middle_col_value+middle_row_sum-3*sample1[n//2][2])
end=time.time()
#print("Time Of Execution Is",end-start)

