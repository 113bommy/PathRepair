n,a,b=map(int,input().split())
sum([i for i in range(n+1) if a<=sum([int(c) for c in str(i)])<=b])