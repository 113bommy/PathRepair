n = int(input())
s  =input()
k="ACTG"
diff=0
ans=1000000
for i in range(n-3):
    a=s[i:i+4]
    for j in range(4):
#        diff+=min(abs(ord(a[j])-ord(k[j])),abs() )
        diff+= min(abs(ord(a[j])-ord(k[j])),26-abs(ord(a[j])-ord(k[j])))
#        print(ord(a[j])-ord(k[j]),a[j],k[j])
    ans=min(diff,ans)
    diff=0
print(ans)        


