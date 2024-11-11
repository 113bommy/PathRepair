N,K,X,Y=[int(input()) for i in range(4)]
print(X*N if N<=K else X*K+Y*(N-K))