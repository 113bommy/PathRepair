n = int(input())
a = list(map(int,input().split()))
res = []
for elem in a:
    if not elem%2:res.append(elem-1)
    else:res.append(elem)
print(*res)