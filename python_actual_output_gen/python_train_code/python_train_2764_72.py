# import sys
# sys.stdin=open("test11.in","r")
# sys.stdout=open("test11.out","w")



n=int(input())
p=list(map(float,input().split()))
s=0
for i in range(n):
	s+=(p[i]/100)
print(float(s/3)*100)
