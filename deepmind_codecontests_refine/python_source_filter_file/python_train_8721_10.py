n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
print('No' if sum([i for i in a if sum(a)/(4*m) <= i]) < m else 'Yes')