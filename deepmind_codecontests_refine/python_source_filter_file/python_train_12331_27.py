import math
x=math.ceil(sum(map(int,input().split()))/5)
y=math.ceil(sum(map(int,input().split()))/5)
z=int(input())
print("YES" if x+y<=z else "NO")
