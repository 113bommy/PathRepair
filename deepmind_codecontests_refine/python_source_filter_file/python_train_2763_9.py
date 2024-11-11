n=int(input())
l=list(map(int,list(input())))
x=True
if n==1:
      print("NO")
else:
      cond1=False
      cond2=False
      cond3=False
      cond4=False
      for i in l:
            c=i
            if c==1 or c==2 or c==3:
                  cond1=True
                  break
      for i in l:
            c=i
            if c==7 or c==9:
                  cond2=True
                  break
      for i in l:
            c=i
            if c==0 or c%3==1:
                  cond3=True
                  break
      for i in l:
            c=i
            if c==0 or c%3==0:
                  cond4=True
                  break
      if cond1 and cond2 and cond3 and cond4:
            print("YES")
      else:
            print("NO")