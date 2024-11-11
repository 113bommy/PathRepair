from collections import Counter
N = int(input())
A = list(map(int, input().split()))

#a = Counter(A)
l_a = len(a)
if(l_a%2 == 0):
     print(l_a-1)
else:
    print(l_a)