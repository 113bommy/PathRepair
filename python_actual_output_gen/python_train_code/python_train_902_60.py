a,b,c = map(int(), input().split())
print("Yes" if (a-c)*(b-c) < 0 else "No")
