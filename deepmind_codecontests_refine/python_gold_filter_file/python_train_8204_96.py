n = int(input())
S = input().strip()
print(max(len(set(S[:i+1]) & set(S[i+1:])) for i in range(n-1)))