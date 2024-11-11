l,r=map(int,input().split())
print("YES")
c=l
for i in range((r-l+1)//2):
    print(c,c+1)
    c+=2