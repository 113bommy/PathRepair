import sys
 
tests = int(sys.stdin.readline())
testcount = 0
while testcount < tests:
    pre, post = map(int, input().split())
    arr = (sys.stdin.readline().split())
    i = 1
    while post > -1:
        if str(i) not in arr:
            post -= 1
        i += 1
    print(i-1)
    testcount += 1