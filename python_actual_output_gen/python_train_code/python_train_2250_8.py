loop = int(input())
s = [0]+list(map(int,input().split()))
e = sorted(s)
for i in range(1, loop+1):
    s[i]+=s[i-1]
    e[i]+=e[i-1]
print(s)
print(e)
loops = int(input())
for i in range(loops):
    a, b, c = map(int, input().split())
    if a == 1:
        print(s[c-1]-s[b-1])
    else:
        print(e[c-1]-e[c-1])