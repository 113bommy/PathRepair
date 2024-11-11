import math
t=int(input())
for i in range(t):
    n=int(input())
    if n>=4:
        q=math.sqrt(n*(n-4))
        a=(n+q)/2
        b=(n-q)/2
        print(f"Y {a} {b}")
    else:
        print("N")