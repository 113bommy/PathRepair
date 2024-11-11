import sys
# sys.stdin = open('E:/Competitive Programming/input.txt', 'r')
# sys.stdout = open('E:/Competitive Programming/output.txt', 'w')
# sys.setrecursionlimit(1000000)
def Ints(): return map(int, sys.stdin.readline().strip().split())
def Strs(): return map(str, sys.stdin.readline().strip().split())
def Array(): return list(map(int, sys.stdin.readline().strip().split()))
def Str(): return sys.stdin.readline().strip()
def Int(): return int(sys.stdin.readline().strip())
def MOD(): return 1000000007

def power(base, power):
    MOD = 1000000007
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % MOD
        power = power // 2
        base = (base * base) % MOD
    return result

if __name__ == "__main__":
    n,t = Ints()
    arr = []
    for i in range(n):
        s, d = Ints()
        while( s < t):
            s += d
        if(s == t):
            print(i+1)
            exit()
        arr.append(s)
    print(arr)
    mn = float("inf")
    indx = -1
    
    for i in range(n):
        if(mn>arr[i]-t):
            mn=arr[i]-t
            indx=i
        if(mn==0):
            break
    print(indx+1)
