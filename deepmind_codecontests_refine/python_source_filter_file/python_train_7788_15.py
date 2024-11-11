from collections import Counter
N = int(input())
V = list(map(int,input().split()))

even = list(Counter(V[0::2]).most_common())
even.append((100001,0))
odd = list(Counter(V[1::2]).most_common())
odd.append((100001,0))
if even[0][0] == odd[0][0]:
    o = []
    o.append(even[0][1]+odd[1][1])
    o.append(even[1][0]+odd[0][1])
    print(N-min(o))
else:
    print(N-even[0][1]-odd[0][1])