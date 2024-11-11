n=int(input())
l=[int(x) for x in input().split()]
diff=0
l.sort()
print(l)
for i in range(0,len(l),2):
    diff+=l[i+1]-l[i]
print(diff)
    