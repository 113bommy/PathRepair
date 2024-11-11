l=list(map(int,input().split()))
if 1 in l :
      print("YES")
elif 2 in l and l.count(2)>=2:
      print("YES")
elif 3 in l and l.count(3)>=3:
      print("YES")
else:
      m=sorted(l)
      if m[0]==4 and m[1]==4 and m[2]==2:
            print("YES")
      else:
            print("NO")