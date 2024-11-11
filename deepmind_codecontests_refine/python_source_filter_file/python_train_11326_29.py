h,w,a,b=map(int,input().split())
w-=a
for i in range(b):print('1'*a+'0'*w)
for i in range(h-b):print('0'*w+'1'*a)