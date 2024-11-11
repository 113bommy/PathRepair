import sys

S=input()

if "[" in S:
    a=S.index("[")
else:
    print(-1)
    sys.exit()

if "]" in S:
    d=S.rindex("]")
else:
    print(-1)
    sys.exit()


if ":" in S[a:]:
    b=S[a:].index(":")+a
else:
    print(-1)
    sys.exit()

if ":" in S[:d]:
    c=S[:d].rindex(":")
else:
    print(-1)
    sys.exit()

if b==c:
    print(-1)
    sys.exit()

ANS=0
if "|" in S[b:c]:
    ANS=S[b:c].count("|")

print(ANS+4)

