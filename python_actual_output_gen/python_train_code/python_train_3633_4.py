s=input()
m=int(input())
for i in range(m):
    l,r,k=[int(x) for x in input().split()]
    k=k%(r-l+1)
    s=s[:l-1]+s[r-k:r]+s[l-1:r-k]+s[r:]
    print(s)
print(s)