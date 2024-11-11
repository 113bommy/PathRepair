def main():
    n, m, k = [int(x) for x in input().split()]

    matr = []
    for i in range(n):
        matr.append(input().split())
    matr = list(zip(*matr))

    score = 0
    repl = 0
    for i in range(m):
        window = count1(matr[i][:k])
        row_scores = []
        for j in range(k, n+1):
            if matr[i][j-k] == '1':
                row_scores.append(window)
                window -= 1
            else:
                row_scores.append(0)

            if j < n and matr[i][j] == '1':
                window += 1

        row_best = max(row_scores)
        ind_best = row_scores.index(row_best)

        repl += count1(matr[i][:ind_best])
        score += row_best
    print(score, repl)


def count1(lst):
    return len(list(filter(lambda x: x == '1', lst)))


if __name__ == "__main__":
    main()
