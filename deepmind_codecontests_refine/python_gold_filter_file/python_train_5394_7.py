N = int(input())
L = list(map(int,input().split()))
print("Yes" if max(L) < sum(L)/2 else "No")