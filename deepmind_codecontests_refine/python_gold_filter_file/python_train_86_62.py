n=list(map(int,input().split()))
n.sort()
print("Yes" if n[2]==n[0]+n[1] else "No")