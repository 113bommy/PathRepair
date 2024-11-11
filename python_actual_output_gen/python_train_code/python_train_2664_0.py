n=int(input());a=sum(map(int,input().split()))
for _ in range(int(input())):
    q,w=map(int,input().split())
    if a<=w:exit(print(a))
print(-1)