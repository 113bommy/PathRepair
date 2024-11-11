n = int(input())
s = list(map(int, input().split()))

m = s[0]
c = 1
ind = 0

for i in range(1, n):
    if s[i]==m :
        c += 1
    elif s[i]<m:
        m = s[i]
        c = 1
        ind = i

if c>1:
    print("Still Rozdill")
else :
    print(ind+1)
