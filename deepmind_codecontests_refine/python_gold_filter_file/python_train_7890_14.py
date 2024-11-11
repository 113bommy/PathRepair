input()
S = input()
K = int(input())

c = S[K-1]

print("".join([v if v == c else "*" for v in S]))
