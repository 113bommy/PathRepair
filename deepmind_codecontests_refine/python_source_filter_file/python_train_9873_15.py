n,a,b = map(int, unput().split())
print(sum(i for i in range(n+1) if a<=sum(map(int,str(i)))<=b))