n,m,a,b = map(int,input().split())
to_demol  = n%m
to_build = max(n,m)- to_demol

t=min(a*to_build,b*to_demol)
print(t)

