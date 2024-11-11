import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


############ ---- Input Functions ---- ############
def in_int():
    return (int(input()))


def in_list():
    return (list(map(int, input().split())))


def in_str():
    s = input()
    return (list(s[:len(s) - 1]))


def in_ints():
    return (map(int, input().split()))

n  = in_int()

m = [[], [], [2], [3], [3,2,2], [5], [5,3], [7], [7,2,2,2], [7,3,3]]
fact = [1]*10

for i in range(1,10):
    fact[i] = fact[i-1]*i

a = in_str()

count = [0]*10
for xx in a:
    nn = int(xx)
    for ll in m[nn]:
        count[ll]  +=1


for i in range(9,1,-1):
    for j in range(count[i]):
        print(i,end='')

