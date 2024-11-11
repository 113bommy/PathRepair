t=int(input())
for i in range(t):
    a,b,x,y=map(int,input().split())
    A1=x*a
    A2=y*b
    A3=(a-1-x)*b
    A4=(b-1-y)*a
    print(max(A1,A2,A3,A4))