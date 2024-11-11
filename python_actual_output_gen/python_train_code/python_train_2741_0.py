n, m = map(int, input().split())
l = [0] * n
inpu=input()
inp = [int(x) for x in inpu.split()]
print(inp)
for i in range(m):
    l[inp[i]-1]+=1
min=1000
for i in range(n):
    if min>l[i]:
        min=l[i]
print(min)
