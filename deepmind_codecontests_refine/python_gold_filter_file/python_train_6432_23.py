N = int(input())
X = [float(x) for x in input().split()]

P = round(sum(X)/N)
print(int(sum([(x-P)**2 for x in X])))