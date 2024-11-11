n = int(input())
b = [int(x) for x in input().split()]
b.sort()
print(int((b[0]+b[1])/2))