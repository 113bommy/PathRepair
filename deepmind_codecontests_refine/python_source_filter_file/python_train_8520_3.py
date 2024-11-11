import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
X = sorted((x,i) for i,x in enumerate((int(x) for x in input().split()),1))

arr = []
for x,i in X:
    arr += [i] * (i-1)
for x,i in X[::-1]:
    arr += [i] * (N-i)

x_to_i = dict(X)

arr = arr[::-1]
answer = []
counter = [0] * (N+1)
bl = True
for x in range(1,N*N+1):
    if x in x_to_i:
        i = x_to_i[x]
        counter[i] += 1
        bl &= (counter[i] == i)
    else:
        i = arr.pop()
        counter[i] += 1
    answer.append(i)

if bl:
    print('Yes')
    print(*answer)
else:
    print('No')