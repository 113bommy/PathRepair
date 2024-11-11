a, b, c = mapt(int, input().split(" "))

print("Yes" if len(set({a,b,c})) == 2 else "No")