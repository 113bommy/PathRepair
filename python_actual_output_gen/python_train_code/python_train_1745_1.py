import sys
input = sys.stdin.readline

'''

'''

n, k = map(int, input().split())
divs = []
for i in range(1, int(n**0.5)+1):
    if n % i == 0:
        divs.append(i)

if k <= len(divs):
    print(divs[k-1])
else:
    if n**0.5 % 1 == 0:
        if k < 2*len(divs):
            print(n // divs[-(k-len(divs))])
        else:
            print(-1)
    else:
        if k <= 2*len(divs):
            print(n // divs[-(k-len(divs))])
        else:
            print(-1)
