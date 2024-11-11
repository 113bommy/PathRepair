A,B,K = map(int, input().split())
A,K = max(0,A-K),max(K-A,A-K)
B = max(0,B-K)
print(A,B)