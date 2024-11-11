N = int(input())
S = input()
print(max([len(set(S[:i]).intersection(set(S[i:]))) for i in range(N)]))
