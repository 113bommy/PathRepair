N = input()

print("Yes" if N%sum(map(int,N))==0 else "No")