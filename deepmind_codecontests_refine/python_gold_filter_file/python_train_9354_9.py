from string import ascii_uppercase
H, W = [int(i) for i in input().split()]
S = [input().split() for _ in range(H)]
for h in range(H):
    for w in range(W):
        if S[h][w] == "snuke":
            print("{}{}".format(ascii_uppercase[w], h+1))
