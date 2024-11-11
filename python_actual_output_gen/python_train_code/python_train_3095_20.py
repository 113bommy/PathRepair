a,b=[int(i) for i in input().split()]
if b!=0:
  s=[int(i) for i in input().split()]
  s.sort()
if b==0:
  print("YES")
elif s[0]==1 or s[-1]==a:
    print("NO")
else:
    x=s[0]
    c=1
    for i in range(1,len(s)):
        if s[i]==x+1:
            c+=1
            if c==3:
                break
        else:
            c=0
        x=s[i]
    if c==3:
        print("NO")
    else:
        print("YES")