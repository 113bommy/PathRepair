#  --*-coding:utf-8-*--

import bisect

N = int(input())
indexess = [[] for _ in range(26)]

S = list(input())
for i, s in enumerate(S):
    indexess[ord(s) - 97].append(i)


Q = int(input())
for _ in range(Q):
    q1,q2, q3 = input().split()
    q2 = int(q2)

    if q1 == '1':
        s0 = S[q2-1]
        if s0 != q3:
            S[q2-1] = q3
            
            indexes = indexess[ord(s0) - 97]
            del indexes[bisect.bisect_left(indexes, q2-1)+1]
            bisect.insort(indexess[ord(q3) - 97], q2-1)

    else:
        cnt = 0
        q3 = int(q3)
        for indexes in indexess:
            
            if bisect.bisect_left(indexes, q2-1) < bisect.bisect_right(indexes, q3-1):
                cnt += 1

        print(cnt)
