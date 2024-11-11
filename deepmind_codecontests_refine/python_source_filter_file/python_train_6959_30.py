import math
n = int(input())
nn = int(math.sqrt(n))
while n%nn != 0: nn-=1
ans = len(str(n/nn))
print(ans)