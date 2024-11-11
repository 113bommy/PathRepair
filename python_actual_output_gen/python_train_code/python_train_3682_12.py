n,m = map(int,input().split())
s = input()
t = input()
k = s.find('*')
if k == -1:
    if s == t:
        print("YES")
        exit(0)
else:
    if k == n-1:
        if s[:n-1] == t:
            print("YES")
            exit(0)
        else:
            print("NO")
            exit(0)
    if (n-1 > m):
        print("NO")
        exit(0)
    if s[:k] == t[:k]:
        o = n-k
        if s[-o+1:] == t[-o+1:]:
            print("YES")
            exit(0)
print("NO")
        
