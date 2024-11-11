import math
for _ in range(int(input())):
    s=set()
    s.add(0)
    n=int(input())
    for i in range(1,math.ceil(math.sqrt(n))+1):
        s.add(i)
        s.add(n//i)
    print(len(s))
    print(*sorted(s))