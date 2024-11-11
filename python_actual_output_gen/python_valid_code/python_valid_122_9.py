def solve(s):
    if len(s) == 1 or len(s) == 2 and ord(s[0]) >= ord(s[1]):
        print("NO")
        return
    print("YES")
    if len(s) >= 3:
        print(s[0], s[1:])
        return 
    print(s[0], s[1])


q = int(input())

for i in range(q):
    
    n = int(input())
    s = str(input())
    solve(s)
