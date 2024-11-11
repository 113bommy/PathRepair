N,M=map(int,input().split())
if N%2==1:
  for i in range(M):
    print(i+1,N-i)
else:
  middle=int((M+1)/2)
  for i in range(middle):
    print(i+1,N-i)
  for j in range(middle,M):
    print(j,N-j)