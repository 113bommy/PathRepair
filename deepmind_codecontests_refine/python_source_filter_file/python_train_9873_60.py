N,A,B = map(int,input().split())
K = 0
for i in range(1,N+1):
  if A <= sum(list(map(int,str(i)))) <= B:
    K += 1
print(K)
    

