inp = list(map(int,input("").split(" ")))
 
n,m = inp[0],inp[1]
 
if n > m+1:
	print(-1)
elif m > n*2+1:
	print(-1)
 
elif n > m:
    print('01' * m + '0')
 
elif m > n * 2:
    print('110' * n + '1' * (m - n * 2))
 
else:
	print('110' * (m - n) + '10' * (n * 2 - m))