n, k = map(int,input().split())
s = input()
check = 0
r = n - 1
l = 0
while r  >= l:
    if s[:l+1] == s[r:]:
        check = l + 1
    r -= 1
    l += 1
if check == 0:
    print(s * k)
else:
    print(s + s[check:]*(k-1))