a,b=map(int,input().split())
s=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,53]
#print(s[0])
#print(len(s))
c=s.index(a)
if b==s[c+1]:
    print("YES")
else:
    print("NO")