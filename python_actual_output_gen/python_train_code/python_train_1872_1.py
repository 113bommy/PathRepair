input()
L=list(map(int,input().split()))
print("Yes" if sum(L)<max(L)*2 else "No")