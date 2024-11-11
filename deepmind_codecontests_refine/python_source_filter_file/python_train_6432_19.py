# c
n = int(input())
x = [int(i) for i in input().split()]

print(  min( sum( (xx-j)**2 for xx in x ) for j in range(max(x)) ) )
