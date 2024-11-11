# import sys
# import time
# sys.stdin=open("utest.in","r")
# sys.stdout=open("utest.out","w")

# n=list(map(int,(input().split())))

# q=""
# for j in range(1,n[1]+1):
# 	q+="#"
# w=""
# for u in range(1,n[1]):
# 	w+="."
# w+="#"
# e=""
# for t in range(1,n[1]+1):
# 	e+="#"
# r="#"
# for i in range(1,n[1]):
# 	r+="."


# if n[0]:



# 	print(q)

n,c=map(int,input().split())
p=list(map(int,input().split()))
q=0
if n==1:
	print("1")
else:
	for i in range(1,n):
		if p[i]-p[i-1]<=c:
			q+=1
		else:
			q=1
	print(q)