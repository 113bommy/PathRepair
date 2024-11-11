n, a, b, c, d = map(int, input().split())
S = input()
if c < d:
    if "##" in S[a-1:d-1]:
        print("No")
    else:
        print("Yes")
else:
    f = S[b-2:d-2].find("...")
    if f != -1 and ("##" not in S[a-1:d-1]):
        print("Yes")
    else:
        print("No")