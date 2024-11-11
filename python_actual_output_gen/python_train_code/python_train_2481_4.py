for i in range(int(input())):
  a,b,c,d,e,f,g,h = map(float,input().split())
  if a == c:
    print("YES" if e == g else "NO")
  elif e == g:
    print("NO")
  else:
    print("YES" if (b-d)/(a-c) - (f-h)/(e-g) < 1e-10 else "NO")


