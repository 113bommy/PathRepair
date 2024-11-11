n,k=map(int,input().split())
for i in range(n):
    	print(' '.join('0'*i+str(k)+'0'*(n-i-1)))