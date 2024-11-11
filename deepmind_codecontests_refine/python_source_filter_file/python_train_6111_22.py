R=lambda:map(int,input().split())
a,b,c=R(),R(),R()
print(*[x for x in b if x in c])