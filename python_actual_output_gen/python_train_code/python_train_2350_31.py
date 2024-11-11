for _ in range(int(input())):
    a,m = map(int,input().split())
    print(a*len(str(m))-a+(len(str(m))==str(m).count('9')))