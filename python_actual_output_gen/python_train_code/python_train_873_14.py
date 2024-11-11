N=int(input())
D,X=map(int,input().split())
print(1+sum((D-1)//int(input())for _ in[0]*N)+X)