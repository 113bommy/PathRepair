print(''.join('..\n.X\n' * (256 - x) + '.X\n' + '..\n.X\n' * x for x in map(ord, input())))
