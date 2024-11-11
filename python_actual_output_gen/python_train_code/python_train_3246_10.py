n = int(input())
s = [set()]*2
ans = ''
for i in range(n*n):
    t = [int(x) for x in input().split()]
    if ((t[0] not in s[0]) and (t[1] not in s[1])):
        ans += str(i+1)+' '
        s[0].add(t[0])
        s[1].add(t[1])

print(ans)        
