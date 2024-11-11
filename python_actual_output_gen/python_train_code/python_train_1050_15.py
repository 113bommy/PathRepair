def I(): return(list(map(int,input().split())))
n=int(input())
x=I()

s=x[0]
prefixarr=[0]*n
prefixarr[0]=x[0]
for i in range(1,n):
	# s+=x[i]
	prefixarr[i]=prefixarr[i-1]+x[i]
prefixarr.append(0)
print(prefixarr)
for i in range(int(input())):
	l,r=I()
	print((prefixarr[r-1]-prefixarr[l-2])//10)
	


