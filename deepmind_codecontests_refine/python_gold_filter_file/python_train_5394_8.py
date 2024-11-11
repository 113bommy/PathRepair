input()
L=list(map(int,input().split()))
print("Yes" if sum(L)-max(L)>max(L) else "No")