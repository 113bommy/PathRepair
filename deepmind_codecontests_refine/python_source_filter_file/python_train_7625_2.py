#https://codeforces.com/contest/1385/problem/C
for t in range(int(input())):
    a = list(input())
    n = len(a)
    r = a.count("R")
    s = a.count("S")
    p = a.count("P")
    m = max(r,s,p)
    if m ==r:
        print("P"*n)
    if m==p:
        print("S"*n)
    if m ==s:
        print("R"*n)
