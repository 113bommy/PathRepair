# cook your dish here
s=input()
for q in range(int(input())):
    l, r, k = map(int, input().split())
    if k>r-l+1:
        k=(r-l+1)%k
    l-=1
    r-=1
    s1=s[:l]
    s2=s[r+1:]
    s3=s[l:r-k+1]
    s4=s[r-k+1:r+1]
    s=s1+s4+s3+s2
print(s)    