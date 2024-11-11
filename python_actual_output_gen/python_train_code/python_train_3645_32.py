X, Y = map(int, input().split())

cnt=1
while 2*X<Y:
	X*=2
	cnt+=1
print(cnt)