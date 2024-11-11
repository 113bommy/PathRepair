n=int(input())
A=B=C=0
for i in range(n):
    a,b,c=map(int,input().split())
    A,B,C=a+max(B,C),max(C,A),max(A,B)
print(max(A,B,C))