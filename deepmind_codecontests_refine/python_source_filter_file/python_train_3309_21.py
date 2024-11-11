S,T=map(input().split())
A,B=map(int,input().split())
U=input()

if S==U:
    print(A-1,B)
if S==T:
    print(A,B-1)