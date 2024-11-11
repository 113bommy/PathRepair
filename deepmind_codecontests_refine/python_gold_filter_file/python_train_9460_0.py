def get_input():
    while True:
        try:
            yield ''.join(input())
        except EOFError:
            break

N = list(get_input())
N.sort()

N1,N2 = N[0].split()
word = N1
pnum = []
pnum.append(int(N2))

for l in range(1, len(N)):
    N1,N2 = N[l].split()

    if word != N1:
        print(word)
        pnum.sort()
        print(pnum[0], end="")
        for i in range(1, len(pnum)):
            print(" ", end="")
            print(pnum[i], end="")
        print("")
        word = N1
        pnum.clear()
        pnum.append(int(N2))
    else:
        pnum.append(int(N2))

print(word)
pnum.sort()
print(pnum[0], end="")
for i in range(1, len(pnum)):
    print(" ", end="")
    print(pnum[i], end="")
print("")
