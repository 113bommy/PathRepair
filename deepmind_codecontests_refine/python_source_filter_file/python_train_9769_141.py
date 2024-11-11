N = input()
print("Yes" if len(set(N[0:2])) == 1 or len(set(N[1:3]))==1 else "No")