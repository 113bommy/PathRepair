n, a, b = map(int,input().split())
s = list(map(int,input().split()))
s.sort()
if s[b] > s[b+1]:
    print(s[b]-s[b-1])
else:
    print(0)