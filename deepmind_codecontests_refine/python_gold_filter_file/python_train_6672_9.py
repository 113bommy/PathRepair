n=int(input())
now_h=max(list(map(int,input().split())))
for i in range(n-1):
	w,h=list(map(int,input().split()))
	if w>now_h and h>now_h:
		print('NO')
		exit()
	elif w<=now_h and h>now_h:
		now_h=w
	elif w>now_h:
		now_h=h
	else:
		now_h=max(w,h)
print('YES')
