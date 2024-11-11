x=int(input())
s=set()
s.add(x)
s.add(x+1)
s.add(x*(x+1))
if len(s)==3:
    print(*list(s))
else:
    print(-1)