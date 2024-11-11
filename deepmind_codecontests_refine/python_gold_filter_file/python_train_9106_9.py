def solve():    
    def check(s):
        for i in range(len(s)):
            if s[i] != s[len(s)-i-1]: return 0
        return 1
    ins = input()
    k = int(input())
    l = len(ins) // k
    if len(ins) % k != 0:
        print("NO")
        return 0
    for i in range(k):
        if not check(ins[i*l:i*l+l]):
            print("NO")
            return 0
    print("YES")
solve()
