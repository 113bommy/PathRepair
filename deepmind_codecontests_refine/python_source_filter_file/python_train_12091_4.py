def emote_problem():
    xmax, imax, flag, sum = 0, 0, 0, 0
    n, m, k = input().split(' ')
    n, m, k = int(n), int(m), int(k)
    input_list = input().split(' ')
    for i, _ in enumerate(input_list):
        input_list[i] = int(input_list[i])
    for i, _ in enumerate(input_list):
        if input_list[i] > xmax:
            imax = xmax
            xmax = input_list[i]
        elif input_list[i] > imax:
            imax = input_list[i]
    if xmax == imax:
        sum = m*xmax
    else:
        sum = int(m/(k+1)*(k*xmax+imax)+m%(k+1)*xmax)
    print(sum)
    return


if __name__ == '__main__':
    emote_problem()
