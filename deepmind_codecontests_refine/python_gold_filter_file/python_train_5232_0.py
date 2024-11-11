import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))

def lis(arr): 
    n = len(arr) 
    lis = [1]*n 
    for i in range (1 , n): 
        for j in range(0 , i): 
            if arr[i]==arr[j]+1 and lis[i]<lis[j] + 1 : 
                lis[i] = lis[j]+1
    ma = 0
    for i in range(n): 
        ma= max(ma , lis[i]) 
    return ma

t,=I()
for _ in range(t):
	n,=I()
	l=I();p=list(l);k=sorted(l)
	d={}
	for i in range(n):
		d[k[i]]=i+1
	for i in range(n):
		l[i]=d[l[i]]
	if k==p:
		print(0);continue
	x=lis(l)
	print(n-x)
