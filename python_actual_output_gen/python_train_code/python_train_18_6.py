n,m=map(int,input().split())
l=[]
for i in range(n):
    l+=list(map(int,input().split()))
print("YES" if len(set(l))==m else "NO")