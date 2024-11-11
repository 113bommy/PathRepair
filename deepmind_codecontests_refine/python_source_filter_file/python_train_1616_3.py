int(input())
x=''
zero=0
for s in input().split():
	if s== '0':print(-1),exit()
	elif s=='1'+'0'*(len(s)-1):zero+=len(s)-1
	else: x=s
print(x+'0'*zero if len(x)>0 else '1'+'0'*zero)	
