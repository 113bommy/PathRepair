def rotate(s,l,r,k):
    size=r-l+1
    k=k%size
    s=s[0:l]+s[r-k+1:r+1]+s[l:r-k+1]+s[r+1:len(s)]

    return s

s=input()
for _ in range(int(input())):
    l,r,k=map(int,input().split(' '))
    s=rotate(s,l-1,r-1,k)
    print(s)
