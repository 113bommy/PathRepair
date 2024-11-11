print(''.join('.\nX\n' * (256 - x) + 'X\n' + '.\nX\n' * x for x in map(ord, input())))
