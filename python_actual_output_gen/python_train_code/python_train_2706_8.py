input()
S = input()
K = int(input())

c = S[K]

print("".join([v if v == c else "*" for v in S]))
