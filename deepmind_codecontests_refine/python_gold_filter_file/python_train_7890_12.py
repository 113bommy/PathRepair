N = input()
S = input()
K = int(input())

tar = S[K-1]

lis = (_ if _==tar else "*" for _ in S)
print("".join(lis))
