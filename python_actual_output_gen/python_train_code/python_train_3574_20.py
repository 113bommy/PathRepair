N, K = map(int, input().split())
D = list(map(int, input().split()))

def isntD(n):
    c = 0
    for i in range(len(str(n))):
        if D.count(int(str(n)[i])) == 1:
            c += 1
    return c
    

while N < 10000:
    if isntD(N) == 0:
        print(N)
        break
    N += 1
