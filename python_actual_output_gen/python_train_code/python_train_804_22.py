# twoplusxorofthirdandminelement

n = int(input())
xs = [ int(a) for a in input().split() ]

third = xs[2]
min_ = min(xs)
print(2 + third ^ min_)
