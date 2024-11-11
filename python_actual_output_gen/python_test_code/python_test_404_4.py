import time as t
def C2(n):
    return int(n*(n-1)/2)

def withoutB(string, n):
    """A bunch of a's with one b"""
    return "a"*(len(string) - n) + "b"*1 + "a"*(n-1)
n = int(input())
cur = t.time()
for i in range(n):
    l, goal = list(map(int, input().split()))

    if goal == 1:
        print("a"*(l-2) + "b"*2)
    else:
        ans = ""

        while goal <= C2(l - 1):
            ans += "a"
            l -= 1

        ans += "b"
        ans += withoutB("a"*(l-2) + "b", goal - C2(l-1))
        print(ans)
print(t.time() - cur)
    
        
