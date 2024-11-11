import sys

def solve():
    validendings = ["lios", "liala", "etr", "etra", "initis", "inites"]
    s = input().split()
    if len(s) == 1:
        if endswith(s[0], validendings):
            print("YES")
            return
        print("NO")
        return
    nounends = ["etr", "etra"]
    nouns = list()
    for i, word in enumerate(s):
        if endswith(word, nounends):
            nouns.append(i)
    if len(nouns) != 1:
        print("NO")
        return
    nounindex, noun = nouns[0], s[nouns[0]]
    malenoun = True if endswith(noun, ["etr"]) else False
    adjectives = list()
    verbs = list()
    for i in range(nounindex):
        word = s[i]
        shouldendwith = "lios" if malenoun else "liala"
        if endswith(word, [shouldendwith]):
            adjectives.append(i)
    for i in range(nounindex + 1, len(s)):
        word = s[i]
        shouldendwith = "initis" if malenoun else "inites"
        if endswith(word, [shouldendwith]):
            verbs.append(i)
    if 1 + len(adjectives) + len(verbs) == len(s):
        print("YES")
        return
    print("NO")


def endswith(word, validendings):
    for ending in validendings:
        if len(word) >= len(ending):
            if word[-len(ending) : ] == ending:
                return True
    return False




def rv(): return map(int, input().split())
def rl(n): return [list(map(int, input().split())) for _ in range(n)]
if sys.hexversion == 50594544 : sys.stdin = open("test.txt")
solve()


