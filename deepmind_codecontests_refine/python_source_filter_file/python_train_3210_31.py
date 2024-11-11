a,s,k=map(int,input().split())
if s-a<=2*k-1:print(*list(range(a,s+1)),sep="\n")
else:print(*list(range(a,a+k)),*list(range(s+1-k,s+1)),sep="\n")