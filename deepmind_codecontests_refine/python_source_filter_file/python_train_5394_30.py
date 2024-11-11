input()
l=sorted(map(int,input().split()))
print("Yes" if sum(l[:3])>l[-1] else "No")