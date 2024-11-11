N,A,B=list(map(int,input().split()))
print(A*(N//(A+B))+max(A,N%(A+B)))