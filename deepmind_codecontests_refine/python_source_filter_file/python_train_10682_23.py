# import sys
# sys.stdin=open("test.in","r")
n,k,t=map(int,input().split())
# c=0
# for i in range(1,t+1):
# 	if i<k or i==k:
# 		c+=1
# 	elif i<=n:
# 		c=c
# 	elif i>n:
# 		c-=1
# print(c)
print(min(n,k,n+k-t))