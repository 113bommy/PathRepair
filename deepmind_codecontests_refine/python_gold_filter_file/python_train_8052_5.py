

def main():
    n = int(input())

    if n == 1:
        print('YES')
        return

    side = {
        (1, 2): (4, 3),
        (1, 3): (5, 2),
        (1, 4): (5, 2),
        (1, 5): (4, 3),
        (2, 3): (1, 6),
        (2, 4): (1, 6),
        (2, 6): (4, 3),
        (3, 5): (1, 6),
        (3, 6): (5, 2),
        (4, 5): (1, 6),
        (4, 6): (5, 2),
        (5, 6): (3, 4)
    }

    bottom = 7 - int(input())
    input()

    for _ in range(n - 1):
        face1, face2 = map(int, input().split())
        top2 = side[(min(face1, face2), max(face1, face2))]
        if bottom not in top2:
            print('NO')
            return
        bottom = top2[0] if top2[0] != bottom else top2[1]
        bottom = 7 - bottom

    print('YES')

if __name__ == "__main__":
    main()