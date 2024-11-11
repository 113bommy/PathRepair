n,m = map(int,input().split())
a = []
b = []
a = [int(s) for s in input().split()]
b = [int(s) for s in input().split()]
zapas = min(a)
predel = max(max(a), zapas*2)
if (max(a)<=predel):
    print(predel)
else:
    print(-1)