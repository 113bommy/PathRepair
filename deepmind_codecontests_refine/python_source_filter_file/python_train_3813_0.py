def cal(col,index,k):
    one = 0
    for i in range(index,len(col)):
        if col[i] == 1:
            for j in range(i,min(len(col),i+k)):
                if col[j] == 1:
                    one += 1
            break

    return one

def solve(col,k):
    change = 0
    score = 0
    n = len(col)
    for i in range(n):
        if col[i] == 1:
            one = 0
            for j in range(i,min(n,i+k)):
                if col[j] == 1:
                    one += 1
            score = one
            break

    remove = 0
    for i in range(n):
        if col[i] == 0:
            change += 1
            one = cal(col,i+1,k)
            if one > score:
                remove = change
                score = one

    return score,remove

def main():
    n,m,k = map(int,input().split())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int,input().split())))

    score = 0
    change = 0
    for i in range(m):
        col = []
        for j in range(n):
            col.append(matrix[j][i])

        curr_score,curr_rem = solve(col,k)
        score += curr_score
        change += curr_rem

    print(score,change)


main()
