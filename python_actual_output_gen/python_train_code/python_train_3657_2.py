def solve():
    s=input()
    n=len(s)
    y=n+1
    l, r = 0, n-1
    while l <= r:
        dl = ord(s[l])
        dr = ord(s[r])
        if dl >= y or dr >= y:
            return False
        if l != r and dl==dr:
            return False
        y = max(dl,dr)
        if dl > dr:
            l+=1
        else:
            r-=1
        
    return True
for _ in range(int(input())):
    print("YES" if solve() else "NO")
        