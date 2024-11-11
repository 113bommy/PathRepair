import re
def count(x):
	return x.count("|")
text = input()
x=(re.split('\+|\=',text))
lst=list(map(count,x))
if x[0]+x[1]==x[2]:
	print(x[0]+"+"+x[1]+"="+x[2])
elif lst[0]>0 and (lst[0]-1)+(lst[1]+1)==lst[2]:
	print("|"*(lst[0]-1)+"+"+"|"*(lst[1]+1)+"="+"|"*lst[2])
elif lst[1]>0 and (lst[0]+1)+(lst[1]-1)==lst[2]:
	print("|"*(lst[0]+1)+"+"+"|"*(lst[1]-1)+"="+"|"*lst[2])
elif lst[0]>0 and (lst[0]-1)+(lst[1])==lst[2]+1:
	print("|"*(lst[0]-1)+"+"+"|"*(lst[1])+"="+"|"*(lst[2]+1))
elif lst[2]>0 and (lst[0]+1)+(lst[1])==lst[2]-1:
	print("|"*(lst[0]+1)+"+"+"|"*(lst[1])+"="+"|"*(lst[2]-1))
elif lst[2]>0 and (lst[0])+(lst[1]+1)==lst[2]-1:
	print("|"*(lst[0])+"+"+"|"*(lst[1]+1)+"="+"|"*(lst[2]-1))
elif lst[1]>0 and (lst[0])+(lst[1]-1)==lst[2]+1:
	print("|"*(lst[0])+"+"+"|"*(lst[1]-1)+"="+"|"*(lst[2]+1))
else:
	print("Impossible")