n, m = map(int, input().split())
l = [0] * n
inpu=input()
inp = [int(x) for x in inpu.split()]
#print(inp)
for i in range(m):
    l[inp[i]-1]+=1
mini=1000
for i in range(n):
    if mini>l[i]:
        mini=l[i]
print(mini)
