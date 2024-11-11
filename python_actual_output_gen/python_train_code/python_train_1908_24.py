N,M,K=map(int,input().split(' '))
print('Yes') if K in [(N-a)*b+(M-b)*a for a in range(N+1) for b in range(N+1)] else print('No')
