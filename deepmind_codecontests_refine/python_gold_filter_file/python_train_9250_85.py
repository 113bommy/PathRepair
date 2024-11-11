N,K,X,Y=[int(input()) for i in range(4)]
print(N*X if N<=K else X*K+Y*(N-K))