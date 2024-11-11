N,K = map(int,input().split())
print(K*max((K-1)**(N-1),1))