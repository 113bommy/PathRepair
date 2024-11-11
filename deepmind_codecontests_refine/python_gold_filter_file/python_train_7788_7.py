from collections import Counter
n = int(input())
V = list(map(int,input().split()))
A = Counter(V[0::2]).most_common(2)
B = Counter(V[1::2]).most_common(2)
A.append((0,0))
B.append((0,0))
if A[0][0]!=B[0][0]:
    print(n-(A[0][1]+B[0][1]))
else:
    print(min(n-(A[1][1]+B[0][1]),n-(A[0][1]+B[1][1])))
