n,m=map(int, input().split())
lst = [0]*(n+1)
cnt = 0
first = []
second = []
llst = []
if m == 0: print(n-1);exit(0)
for i in range(m):
    a,b=map(int, input().split())
    first.append(min(a,b))
    second.append(max(a,b))
    lst[a]=1
    lst[b]=1
if len(set(first).intersection(set(second))):
    print(0)
else:
    mx = max(first)
    mn = min(second)
    print(mn-mx)