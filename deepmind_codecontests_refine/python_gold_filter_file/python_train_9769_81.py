N = input()
print("Yes" if len(set(N[0:3])) == 1 or len(set(N[1:4]))==1 else "No")