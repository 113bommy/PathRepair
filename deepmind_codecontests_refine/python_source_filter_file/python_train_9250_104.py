N,K,X,Y=[int(input()) for i in range(4)]
print((N-K)*Y+K*X if (N-K)>=0 else K*N)