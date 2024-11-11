import sys
a = [print(len(sum(map(int, line.split())))) for line in sys.stdin]