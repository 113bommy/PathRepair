

n, p, q = map(int, input().split())
text = input()

tab = []

while len(text) >= p and len(text) % q != 0:
    tab += [text[-p:]]
    text = text[:-p]

if len(text) % q == 0:
    while len(text) > 0:
        tab += [text[-q:]]
        text = text[:-q]
    print(len(tab))
    print("\n".join(reversed(tab)))
else:
    print(-1)

