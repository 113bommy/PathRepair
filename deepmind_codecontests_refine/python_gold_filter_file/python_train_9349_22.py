K,A,B=map(int,input().split())
c=K-A+1;d=B-A
print(K+1 if d<2 or c<1 else A+c%2+c//2*d)