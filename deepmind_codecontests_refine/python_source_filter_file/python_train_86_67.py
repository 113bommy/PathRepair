n=list(map(int,input().split()))
n.sort()
print("YES" if n[2]==n[0]+n[1] else "NO")