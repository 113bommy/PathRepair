def main():
    white = 0
    black = 0
    for i in range(8):
        line = input()
        white += 9 * line.count('Q')

        white += 5 * line.count('R')
    
        white += 3 * line.count('B')
        
        white += 3 * line.count('K')
        
        white += 1 * line.count('P')
        
        black += 9 * line.count('q')
        black += 5 * line.count('r')
        black += 3 * line.count('b')
        
        black += 3 * line.count('k')
        
        black += 1 * line.count('p')
    if white > black:
        print('White')
    elif black > white:
        print('Black')
    else:
        print('Draw')
main()
