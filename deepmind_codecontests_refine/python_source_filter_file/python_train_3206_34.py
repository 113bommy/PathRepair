A,B,K = map(int,input().split())
x = A-K
B = max(B+x,0)
A = max(x,0)
print(A,B)