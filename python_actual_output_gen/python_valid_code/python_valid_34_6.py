
import sys

############ THE WAY TO HOME #############

def get_last_index(s, jumpLength):
    indexes = list()
    for i in range(len(s)):
        if s[i] == '1': indexes.append(i)
    if not [j for j in indexes if j < jumpLength]: return -1
    else: return max([j for j in indexes if j < jumpLength])


def min_number(jumpLength, s, count=0):
    if len(s) == 0: return count
    elif (s == '1'*len(s) and jumpLength == 1): return (len(s)-1)
    else:
        i = get_last_index(s, jumpLength)
        if i == -1: return -1
        if jumpLength >= i: return min_number(jumpLength, s[i+1:], count+1)




if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    ls = [int(i) for i in input().split()]
    s = input()
    print(min_number(ls[1], s[1:]))
