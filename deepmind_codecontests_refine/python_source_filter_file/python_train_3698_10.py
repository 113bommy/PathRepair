def main():
    n = int(input())
    q = str(input())
    # 0 = B, 1 = G, 2 = R
    d = [0] * 3

    for e in q:
        if e == "B":
            d[0] += 1
        elif e == "G":
            d[1] += 1
        else:
            d[2] += 1

    answer = ""

    if d[0] != 0 and d[1] != 0:
        answer += "R"
        if d[0] > 1:
            answer += "G"

        if d[1] > 1:
            answer += "B'"

    if d[0] != 0 and d[2] != 0:
        answer += "G"
        if d[0] > 1:
            answer += "R"

        if d[2] > 1:
            answer += "B"

    if d[1] != 0 and d[2] != 0:
        answer += "B"
        if d[1] > 1:
            answer += "R"

        if d[2] > 1:
            answer += "G"

    if d[0] > 0 and d[1] == 0 and d[2] == 0:
        answer += "B"

    if d[1] > 0 and d[0] == 0 and d[2] == 0:
        answer += "G"

    if d[2] > 0 and d[0] == 0 and d[1] == 0:
        answer += "R"

    q = ""
    for e in sorted(list(set(answer))):
        q += e

    print(q)

if __name__ == "__main__":
    main()