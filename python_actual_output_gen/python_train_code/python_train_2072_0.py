input()
print(*['Infinite' if p * pow(b, 20, q) % q else 'Finite' for p, q, b in map(lambda l: map(int, l.split()), __import__('sys').stdin.readlines())], sep='\n')
