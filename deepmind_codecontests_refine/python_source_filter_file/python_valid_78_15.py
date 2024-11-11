for i in range(int(input())):
      l,r = map(int,input().split())
      a = max(l,r)
      b = min(l,r)
      if l==1 and r==1:
            print(0)
      else:
            if a%2==0:
                  t = a//2
                  if t>=l:
                        print(t-1)
                  else:
                        print(a%b)
            else:
                  t = a-1
                  if t>=l:
                        print(t//2)
                  else:
                        print(a%b)
