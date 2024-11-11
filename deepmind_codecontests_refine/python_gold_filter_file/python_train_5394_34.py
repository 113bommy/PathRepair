n=int(input())
l=list(map(int, input().split()))
print("Yes" if (sum(l)>max(l)*2) else "No")
