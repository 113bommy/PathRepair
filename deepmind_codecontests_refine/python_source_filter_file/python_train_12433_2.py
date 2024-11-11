__author__ = 'linh'

def main():
    matrix = []
    dot_n0 = 0
    X_n0 = 0
    O_n0 = 0
    for i in range(0,3):
        str = input()
        dot_n0 += str.count('.')
        X_n0 += str.count('X')
        O_n0 += str.count('0')
        matrix.append(list(str))


    if dot_n0 + X_n0 + O_n0 != 9:
        print("illegal")
        return
    elif (X_n0 > O_n0+1) or (O_n0>X_n0):
        print("illegal")
        return
    else:
        for i in range(0,3):
            if matrix[i][0] == matrix[i][1] == matrix[i][2]:
                if matrix[i][0] == 'X':
                    if X_n0 == O_n0:
                        print("illegal")
                    else:
                        print("the first player won")
                    return
                elif matrix[i][0] == '0':
                    if X_n0 == O_n0+ 1:
                        print("illegal")
                    else:
                        print("the second player won")
                    return

            if matrix[0][i] == matrix[1][i] == matrix[2][i]:
                if matrix[0][i] == 'X':
                    if X_n0 == O_n0:
                        print("illegal")
                    else:
                        print("the first player won")
                    return
                elif matrix[0][i] == '0':
                    if X_n0 == O_n0+ 1:
                        print("illegal")
                    else:
                        print("the second player won")
                    return
        if matrix[0][0] == matrix[1][1] == matrix[2][2]:
            if matrix[0][i] == 'X':
                if X_n0 == O_n0:
                    print("illegal")
                else:
                    print("the first player won")
                return
            elif matrix[0][i] == '0':
                if X_n0 == O_n0+ 1:
                    print("illegal")
                else:
                    print("the second player won")
                return
        if matrix[0][2] == matrix[1][1] == matrix[2][0]:
            if matrix[0][i] == 'X':
                if X_n0 == O_n0:
                    print("illegal")
                else:
                    print("the first player won")
                return
            elif matrix[0][i] == '0':
                if X_n0 == O_n0+ 1:
                    print("illegal")
                else:
                    print("the second player won")
                return
        if dot_n0 == 0:
            print("draw")
            return
        elif X_n0 == O_n0:
            print("first")
            return
        else:
            print("second")
            return




if __name__ == '__main__':
    main()
