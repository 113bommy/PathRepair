n = int(input())
f = []
l = list(map(int,input().split()))
s = sum(l)
for i in range(len(l)):
    if (s-l[i])//(n-1) == l[i]:
        f.append(i+1)
print(len(f))
f.sort()
print(*f)