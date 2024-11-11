n = input()
print("Yes" if n%sum(map(int,n))==0 else "No")
