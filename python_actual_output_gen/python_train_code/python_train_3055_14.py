n = int(input())
s = input() + '$'
ans = s[0]
cnt = 0
for i in range(1,n) :
    if ( ans != s[i] ) :
        ans = s[i]
        cnt += 1
print(n-cnt)