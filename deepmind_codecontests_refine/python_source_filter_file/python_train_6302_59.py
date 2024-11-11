# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("output1.out","w")
N=int(input())
X="1"
for i in range(2,1000):
	X=X+str(i)
Y=list(X)
print(Y[N-1])
print(Y)