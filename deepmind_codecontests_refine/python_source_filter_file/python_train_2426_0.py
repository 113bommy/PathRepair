from sys import stdin, stdout
from collections import deque

def painting_the_array_2(n, a_a):
    dic = {}
    ua_a = [a_a[0]]
    dic[a_a[0]] = deque()
    dic[a_a[0]].append(0)
    for i in range(1, n):
        if a_a[i] == a_a[i-1]:
            continue
        ua_a.append(a_a[i])
        if a_a[i] not in dic:
            dic[a_a[i]] = deque()
        dic[a_a[i]].append(i)

    r = 0
    one = -1
    two = -1

    # print(dic)

    for a in ua_a:
        if one == a:
            one = a
        elif two == a:
            two = a
        elif one == -1:
            one = a
            r += 1
        elif two == -1:
            two = a
            r += 1
        else:
            if len(dic[one]) == 0:
                two = a
            elif len(dic[two]) == 0:
                one = a
            elif dic[one][0] > dic[two][0]:
                one = a
            else:
                two = a
            r += 1
        dic[a].popleft()

    return r


n = int(stdin.readline())
a_a = list(map(int, stdin.readline().split()))
r = painting_the_array_2(n, a_a)
stdout.write(str(r))
