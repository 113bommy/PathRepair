def ii():return int(input())
def si():return input().rstrip()
def mi():return map(int,input().split())
for _ in range(ii()):

    a,b,c,d = mi()
    print(max(a+b,c+d))