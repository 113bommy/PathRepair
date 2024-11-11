S=sorted(list(map(int,input().split())))
print("Yes" if sum(S[:2])==S[2] else "No")