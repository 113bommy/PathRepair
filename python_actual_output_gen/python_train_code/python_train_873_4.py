N=int(input())
D,X=map(int,input().split())
a=0
for i in range(N):
    A=int(input())
    a+=(D//A)+1
print(X+a)