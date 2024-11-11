# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out1.out",'w')
n,k=map(int,input().split())
a=list(map(int,input().split()))
x=2*(n*(k-0.5)-sum(a))	
print(max(0,int(x)))