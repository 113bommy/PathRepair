import math

def better(a, b):
    for i in range(min(len(a), len(b))):
        if ord(a[i]) < ord(b[i]):
            return True
        elif ord(a[i]) > ord(b[i]):
            return False
    return len(a) < len(b)

def optimize(a):
    occ = [0] * 26
    for i in range(len(a)):
        occ[ord(a[i]) - ord('A')] += 1
    p1 = -1
    p2 = -1
    t = 0
    for i in range(len(a)):
        if p1 < 0:
            occ[ord(a[i]) - ord('A')] -= 1
            for j in range(ord(a[i]) - ord('A')):
                if occ[j] > 0:
                    p1 = i
                    t = j
                    break
        elif p2 < 0:
            if ord(a[i]) - ord('A') == t:
                p2 = i

    if p1 >= 0 and p2 >= 0:
        return a[:p1] + a[p2] + a[p1+1:p2] + a[p1] + a[p2+1:]
    return a

def main():
    t = int(input())
    for i in range(t):
        line = str(input())
        p = line.split()
        mine = p[0]
        yours = p[1]
        new = optimize(mine)
        if better(new, yours):
            print(new)
        else:
            print('---')

if __name__ == '__main__':
    main()
