A, B = map(int, input().split())
c = B - A
print(c*(c+1)//2 - B)