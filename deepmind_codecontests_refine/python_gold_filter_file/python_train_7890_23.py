N = int(input())
S = input()
K = int(input())

t = S[K-1]
newS = [s if s == t else '*' for s in S]
print(''.join(newS))