# 34B
import itertools
(_,m) = (int(_) for _ in input().split(' '))
a = [int(_) for _ in input().split(' ')]
a.sort()
negatives = list(itertools.takewhile(lambda x: x < 0, a))
print(-sum(negatives[:m]))