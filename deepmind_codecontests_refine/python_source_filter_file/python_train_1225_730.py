n,k= map(int,input().split())
s = map(int,input().split())
s.sort()
print(sum(s[:k]))