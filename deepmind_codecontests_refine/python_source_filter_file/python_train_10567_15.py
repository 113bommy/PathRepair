s = str(input())
m = int(input())
for i in range(m):
    l,r,k = map(int,input().split())
    k%r-l+1
    st = ''
    st += s[:l-1] + s[r-k:r] + s[l-1:r-k] + s[r:]
    s = st
print(s)