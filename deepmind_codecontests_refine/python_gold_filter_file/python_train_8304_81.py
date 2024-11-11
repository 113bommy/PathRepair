a,b = map(int, input().split())
h = list(map(int,input().split()))
print("Yes" if sum(h) >= a else "No")