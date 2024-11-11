def main():
    for _ in range(int(input())):
        a, b, c, d = [int(x) for x in input().split()]
        
        is_negative_sign = (a + b) & 1
        can_be_large = a or d
        can_be_small = b or d
        
        
        if is_negative_sign:
            print('Ya' if can_be_large else 'Tidak', end = ' ')
            print('Ya' if can_be_small else 'Tidak', end = ' ')
            print('Tidak Tidak')
        else:
            print('Tidak Tidak', end = ' ')
            print('Ya' if can_be_small else 'Tidak', end = ' ')
            print('Ya' if can_be_large else 'Tidak')

main()