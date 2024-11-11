from sys import stdin,stdout

def main(k, p):
    i = 1
    s = 0
    while True:
        s = (s + (int(str(i) + str(i))) % p) % p
        i += 1
        if i > k:
            break
    return s

stdout.write('{}\n'.format(main(*list(map(int, stdin.readline().strip().split(' '))))))
