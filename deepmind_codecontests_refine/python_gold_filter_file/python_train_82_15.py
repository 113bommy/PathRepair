import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def sub(a,b,c,d):
    x1 = a - (a - (c+1))//b * b
    if d<b:
        ans = "No"
    elif a<b:
        ans = "No"
    elif d%b==0:
        if x1>=b:
            ans = "Yes"
        else:
            ans = "No"
    else:
        k = gcd(d,b)
        x2 = x1 - (x1 - (c+1))//k * k
        if x2>=b:
            ans = "Yes"
        else:
            ans = "No"
    return ans

t = int(input())
ans = []
for i in range(t):
    a,b,c,d = map(int, input().split())
    ans.append(sub(a,b,c,d))
write("\n".join(ans))