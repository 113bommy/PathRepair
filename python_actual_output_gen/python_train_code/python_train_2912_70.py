n = int(input())
for i in range(n + 1, 9001):
    a, b, c, d = str(i)[0], str(i)[1], str(i)[2], str(i)[3]
    if len(set([a, b, c, d])) == 4:
        print(i)
        break
