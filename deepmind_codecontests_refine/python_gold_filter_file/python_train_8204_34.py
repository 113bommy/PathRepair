N = int(input())
S = input()
print(max(len(set(S[:n])&set(S[n:])) for n in range(N)))