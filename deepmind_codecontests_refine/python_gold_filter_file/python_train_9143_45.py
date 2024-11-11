A,B,C,D=map(int,input().split())
print(max(-max(A,C)+min(B,D),0))