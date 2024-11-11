import sys


def main():
    stdin = sys.stdin.read().split('\n')
    
    A, B = [], []
    for row in range(8):
        for col in range(8):
            if stdin[row][col] == 'W':
                A.append((row, col))
            if stdin[row][col] == 'B':
                B.append((row, col))
    
    Acount = []
    for a in A:
        if all(stdin[i][a[1]] == '.' for i in range(a[0])):
            Acount.append(a[0])
    Bcount = []
    for b in B:
        if all(stdin[i][b[1]] == '.' for i in range(b[0]+1, 8)):
            Bcount.append(7-b[0])
    
    if min(Acount) <= min(Bcount):
        print('A')
    else:
        print('B')


if __name__ == '__main__':
    main()
