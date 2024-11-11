for _ in range(int(input())):
    a,m = map(int,input().split())
    print(a*(len(str(m))-1+(len(str(m))==str(m).count('9'))))