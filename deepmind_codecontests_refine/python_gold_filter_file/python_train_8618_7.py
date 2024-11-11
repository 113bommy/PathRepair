N,K = map(int, input().split())
A=list(map(int, input().split()))
print(len([i for i in A if i >= K]))