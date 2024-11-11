n = int(input())

pos = [x for x in input().split()]
pos.sort()

print(pos[(n-1)//2])
