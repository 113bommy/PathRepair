n = int(input())
a = list(map(int,input().split()))
c = [0]*n
for x in a:
    c[x-1] += 1
for x in c:
    print(x)
