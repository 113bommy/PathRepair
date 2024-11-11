a,b,k=map(int,input().split())
A=max(a-k,0)
B=max(b-(k-A),0)  
print(A,B)