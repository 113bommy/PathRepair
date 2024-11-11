n,m=map(int,input().split())
l=[]
for i in range(n):
    l+=list(map(int,input().split()))[1:]
print("YES" if len(set(l))==m else "NO")