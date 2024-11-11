
d = {}

n = int(input())

def simpler(word):
    p = 0
    while p <= len(word):
        if word[p:p+1] == "u":
            word = word[:p] + "oo" + word[p+1:]
            p = 0
        elif word[p:p+2] == "kh":
            word = word[:p] + "h" + word[p+2:]
            p = 0
        else:
            p += 1
    return word

for i in range(n):
    word = simpler(input())
    if word not in d:
        d[word] = 1
    else:
        d[word] = d[word] + 1

print(len(d),d)
