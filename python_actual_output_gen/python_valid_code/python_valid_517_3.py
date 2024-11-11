rint = lambda: int(input())
rli = lambda: list(map(int,input().split()))
rl = lambda: input().split()
def strm(m):
    s = ""
    for i in range(len(m)):
        for j in range(len(m[0])):
            s += str(m[i][j])
        s += '\n'
    return s

def solve():
    s = input()
    t = input()

    if len(s)<len(t):
        return "NO"
    if s == t:
        return "YES"

    if s[-len(t):] == t:
        return "YES"

    k = len(s)-1
    j = len(t)-1

    while j != 0 and k >= 0:
        if s[k]==t[j]:
            k-=1
            j-=1
        else:
            k-=2

    if j == -1:
        return "YES"
    return "NO"

res = ""
for test_number in range(1,rint()+1):
    r = solve()
    print(r)
    res+=r+"\n"