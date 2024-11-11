n, a, b, c, d = map(int, input().split())
S = input()

if c < d and (S[a-1:d+1].count("##") == 0):
    print("Yes")
    exit()

if c > d and (S[b-1:d+1].count("...") >= 1) and (S[a-1:d+1].count("##") == 0):
    print("Yes")
    exit()

print("No")
