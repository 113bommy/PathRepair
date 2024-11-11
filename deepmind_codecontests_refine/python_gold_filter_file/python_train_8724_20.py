n,m=map(int,input().split())
print(len(set.intersection(*[set(input().split()[1:])for _ in[0]*n])))