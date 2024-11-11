n=int(input())
g=input()
r=0
for i in range(4,len(g),n):
    if g[i-1] == g[i-2] == g[i-3]:
        r+=1
print(r)
