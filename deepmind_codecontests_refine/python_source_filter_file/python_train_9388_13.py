import math
t = int(input())

for i in range(t):
    delta = input()
    delta = delta.split()
    for i in range(2):
        delta[i]=int(delta[i])
    heads = delta[1]
    m = 0
    s = []
    for i in range(delta[0]):
        gamma = input()
        gamma = gamma.split()
        for i in range(2):
            gamma[i]=int(gamma[i])
        s.append(gamma[0]-gamma[1])
        if(gamma[0]>m):
            m = gamma[0]
    s.sort()
    val = s[-1]
    if(heads<m):
        print(1)
        continue
    if val<=0:
        print(-1)
        continue
    # moves = 0
    heads -=m
    moves = math.ceil(heads/m)+1
    print(moves)
