import sys

def input():
    return sys.stdin.readline().strip()

def dinput():
    return int(input())

def tinput():
    return input().split()

def rinput():
    return map(str, tinput())

def rt(a, s):
    t = ""
    z = 0
    x = len(a)
    y = len(s)
    while z < x and z < y:
        t = t + a[z] + s[z]
        z += 1
    print(y, x , t)
    if y > x:
        t = t + s[z:]
    else:
        t = t + a[z:]
    return int(t)
        
    
    

def main():
    n = dinput()
    q = list(rinput())
    w = {}
    ans = 0
    for i in q:
        if len(i) not in w:
            w[len(i)] = 1
        else:
            w[len(i)] = w[len(i)] + 1
    for i in range(n):
        y = ""
        x = ""
        for j in range(1, 11):
            c = q[i]
            if len(c) > j:
                a = c[0 : len(c) - j]
            else:
                a = ""
            if len(c) - j >= 0:
                y = "0" + c[len(c) - j] + y
                x =  c[len(c) - j] + "0" + x
            l = y + a
            r = x + a
            if j in w:
                ans += int(l) * w[j]
                ans += int(r) * w[j]       
    print(ans % 998244353)
main()