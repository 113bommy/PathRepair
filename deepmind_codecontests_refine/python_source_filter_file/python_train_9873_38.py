N,A,B = [map(int,input().split())]
print(sum(i for i in range(n+1) if A <= sum(map(int,str(i))) <= B))