n = int(input())
x = [int(i) for i in input().split()]

print(  min( sum( (xx-p)**2 for xx in x ) for p in range(max(x)+2) ) )