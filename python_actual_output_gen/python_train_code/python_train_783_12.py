q = input().split(' ')
n = int(q[0])
k = int(q[1])
s = input()
g = s[s.find("G")%k::k]
if (s.find("T")>-1):
    w = [s.find("G"),s.find("T")]
    w.sort()
    q = g[w[0]+1:w[1]]
    if (q.find("#")==-1):
        print("YES")
    else:
        print("NO")
else:
    print("NO")
