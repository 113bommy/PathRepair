from sys import stdin, stdout
n, k = stdin.readline().rstrip().split()
stdout.write(str(bin(int(k))[2:][::-1].count('1')+1))
