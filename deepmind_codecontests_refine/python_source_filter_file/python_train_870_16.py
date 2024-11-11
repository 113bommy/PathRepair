def main():
    wires = int(input())
    ls = list(map(int, input().split()))
    shots = int(input())
    while shots > 0:
        w, b = map(int, input().split())
        if 1 < w < wires:
            temp = ls[w-1]
            ls[w-1] = 0
            ls[w-2] += (b-1)
            ls[w] += (temp-b)
        elif w == 1:
            temp = ls[w-1]
            ls[0] = 0
            if wires > 1:
                ls[1] += (temp-b)
        else:
            temp = ls[w-1]
            ls[w-1] == 0
            if wires > 1:
                ls[w-2] += (b-1)
        shots -= 1
    for i in ls:
        print(i)

if __name__ == '__main__':
    main()