n, m = map(int, input().split())
shorter = []
longer = []

for i in range(m):
    word1, word2 = map(str, input().split())

    if len(word1) <= len(word2):
        shorter.append(word1)
        longer.append(word2) 
    else:
        shorter.append(word2)
        longer.append(word1)

lecture = map(str, input().split())

for word in lecture:
    if word in longer:
        print(shorter[longer.index(word)], end = '')
    else:
        print(shorter[shorter.index(word)], end = '')
