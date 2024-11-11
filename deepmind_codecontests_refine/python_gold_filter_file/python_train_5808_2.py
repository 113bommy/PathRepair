
itos = ["A", "B", "C"]

def swap(ABC, f, t):
    ABC[f] -= 1
    ABC[t] += 1
    return itos[t]


def main():
    N, A, B, C = map(int, input().split())
    S = [input() for i in range(N)]
    ABC = [A, B, C]
    StoP = {"AB": (0, 1), "BC": (1, 2), "AC": (0, 2)}
    itos = ["A", "B", "C"]
    L = []
    for i in range(N):
        x, y = StoP[S[i]]

        if ABC[x] == 0 and ABC[y] == 0:
            print("No")
            return
        if ABC[x] == 1 and ABC[y] == 1 and i < N - 1 and S[i] != S[i+1]:
            x2, y2 = StoP[S[i+1]]
            if x in [x2, y2]:
                L.append(swap(ABC, y, x))
            else:
                L.append(swap(ABC, x, y))
        elif ABC[x] < ABC[y]:
            L.append(swap(ABC, y, x))
        else:
            L.append(swap(ABC, x, y))

    print("Yes")
    print(*L, sep='\n')
if __name__ == '__main__':
    main()