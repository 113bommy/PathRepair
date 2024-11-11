a,b = map(int,input().split())
N = list(map(int,input().split()))
print("Yes" if sum(N) >= a else "No")