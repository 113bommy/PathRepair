#
# Author: eloyhz
# Date: Sep/07/2020
#

if __name__ == '__main__':
    n = int(input())
    road = input()
    s = t = None
    for i in range(n - 1):
        if road[i] == 'R' and road[i + 1] == 'L':
            s = i
            t = i + 1
            break
    if s == t == None:
        right = True
        if road.count('R') > 0:
            s = road.find('R') + 1
        else:
            right = False
            s = road.find('L') + 1
        for t in range(s, n):
            if road[t] == '.':
                break
        if not right:
            s, t = t, s
            t -= 1
        else:
            t += 1
    print(s, t)
