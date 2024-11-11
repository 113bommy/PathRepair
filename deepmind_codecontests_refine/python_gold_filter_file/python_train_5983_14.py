n,c = map(int,input().split())
s = input()

ans = 0;first  = n-1;last = 0

for i in range(n//2):
    if s[i] != s[n-i-1]:
        first = min(first,i)
        last = max(last,i)
        a = ord(s[i])-97;b = ord(s[n-i-1])-97
        change = min(a,b) + 26 - max(a,b)
        #print(change,s[i])
        ans += min(abs(b-a),change)

#print(first,last,ans)
if c == n//2:
    ans += n//2 - first
elif c < n//2:
    c-=1
    a = c-min(c,first)
    b = max(c,last)-c
    #print(a,b)
    ans += a+b+min(a,b)

else:
    c = n-c
    a = c-min(c,first)
    b = max(c,last)-c
    #print(a,b)
    ans += a+b+min(a,b)

print(max(0,ans))
