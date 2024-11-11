for _ in range(int(input())):
      a=list(map(int,input().split()))
      x=sorted(a[:3])
      k=a[3]-(x[2]-x[0])-(x[2]-x[1])
      if(k>-1 and k%3==0):
            print("YES")
      else:
            print("NO")