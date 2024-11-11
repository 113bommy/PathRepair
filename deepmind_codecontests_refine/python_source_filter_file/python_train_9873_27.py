N,A,B=map(int,raw_input().split())
print(sum([i for i in range(1,N+1) if A<=sum(map(int,str(i)))<=B]))