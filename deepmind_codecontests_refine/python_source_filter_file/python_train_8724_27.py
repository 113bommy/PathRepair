n,m=map(int,input().split())
print(len(set.intersection(*[set(input().split())for _ in[0]*n]))-1)