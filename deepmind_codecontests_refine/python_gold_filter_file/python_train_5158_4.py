if __name__ == '__main__':
    x, y = str(input()).split()
    x = int(x)
    y = int(y)
    line_x = [x//5] * 5
    for i in range(x % 5):
        line_x[i+1] += 1
    line_y = [y//5] * 5
    for i in range(y % 5):
        line_y[i+1] += 1
    print(sum([
        line_x[0]*line_y[0],
        line_x[1]*line_y[4],
        line_x[2]*line_y[3],
        line_x[3]*line_y[2],
        line_x[4]*line_y[1]
    ]))
