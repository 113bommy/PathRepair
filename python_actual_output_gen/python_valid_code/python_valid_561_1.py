def solve(s):
    n = len(s)
    for k in range(n):
        x = k
        a = 0
        b = 0
        while x>=0:
            if s[x]=="a": a+=1
            if s[x]=="b": b+=1
            if a==b:
                return [x+1, k+1]
            x-=1
    return [-1, -1]
for _ in range(int(input())):
    n = int(input())
    print(solve(input()))