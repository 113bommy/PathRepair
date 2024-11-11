def solve(s):
    st=s[::-1]
    if all((st[u]==s[u]) or abs(ord(s[u])-ord(st[u]))==2 for u in range(len(s))):
        print("YES\n")
    else :
        print("NO\n")
        
t=int(input())
for x in range(t):
    input()
    s=input()
    print (solve(s))