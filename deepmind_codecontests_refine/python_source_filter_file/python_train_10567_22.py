s = input()
m = int(input())
for i in range(m):
    l, r, k = [int(x) for x in input().split()]
    k = k % (r+1-l)
    s = s[:l-1]+s[r-k]+s[l-1:r-k]+s[r:]
print(s)