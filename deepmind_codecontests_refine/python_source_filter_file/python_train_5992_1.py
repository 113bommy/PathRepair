n = int(input().strip())
m = sorted([[int(x), i] for i,x in enumerate(input().strip().split())])
for i in range(n//2):
    print("{0} {1}".format(m[i][1], m[-i-1][1]))