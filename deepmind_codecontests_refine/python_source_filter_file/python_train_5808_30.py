n,a,b,c=[int(x) for x in input().split()]
S=[input() for i in range(n)]
ans=""
for i in range(n):
  s=S[i]
  if s=="AB":
    if a==0 and b==0:
      print("No")
      exit()
    elif a>b:
      ans+="B\n"
      a-=1
      b+=1
    elif b>a:
      ans+="A\n"
      a+=1
      b-=1
    else:
      if i+1<n and S[i+1]=="AC":
         ans+="A\n"
         a+=1
         b-=1
      else:
         ans+="B\n"
         a-=1
         b+=1
  elif s=="AC":
    if a==0 and c==0:
      print("No")
      exit()
    elif a>c:
      ans+="C\n"
      a-=1
      c+=1
    elif c>a:
      ans+="A\n"
      a+=1
      c-=1
    else:
        if i+1<n and S[i+1]=="BC":
            ans+="C\n"
            a-=1
            c+=1
        else:
            ans += "A\n"
            a+=1
            c-=1
  elif s=="BC":
    if c==0 and b==0:
      print("No")
      exit()
    elif c>b:
      ans+="B\n"
      c-=1
      b+=1
    elif b>c:
      ans+="C\n"
      c+=1
      b-=1
    else:
        if i+1<n and S[i+1]=="AB":
            ans += "B\n"
            b+=1
            a-=1
        else:
            ans+="A\n"
            a+=1
            b-=1
print("Yes")
print(ans,end="")