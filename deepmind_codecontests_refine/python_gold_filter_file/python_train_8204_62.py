N = int(input())
S = input()
print(max([len(set(S[:x]) & set(S[x:])) for x in range(N)]))