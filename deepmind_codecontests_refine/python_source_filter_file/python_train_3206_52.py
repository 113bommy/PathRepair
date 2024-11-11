A,B,K = map(int, input().split())
print(max(A-K,0),max(B-abs(A-K),0))