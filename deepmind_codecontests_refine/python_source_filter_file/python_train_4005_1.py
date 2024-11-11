from sys import stdin
input = stdin.readline
def put():
    return map(int, input().split())

def fail():
    print(-1)
    exit()

t = int(input())
for _ in range(t):
    l,r = put()
    
    while (l|(l+1))<r:
        l = l|(l+1)

    print(l)