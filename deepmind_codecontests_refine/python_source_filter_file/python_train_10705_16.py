x=int(input())
print("Yes" if x%sum(list(str(x)))==0 else "No")