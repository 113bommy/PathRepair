N,A,B = map(int,input().split())
K = 0
for i in range(1,N+1):
  if A <= sum(map(int,str(i))) <= B:
    K += i
print(K)
    

