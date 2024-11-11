n = int(input())
L = map(int,input().split())
print("Yes" if max(L)<sum(L)-max(L) else "No")