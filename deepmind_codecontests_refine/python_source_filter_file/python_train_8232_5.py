n,h,a,b,k=map(int,input().split())
x , ff = 0, 0
for i in range(k):
     ta,fa,tb,fb=map(int,input().split())
     x = 0
     if ta == tb :
      x = abs(fa-fb)
     else:
          if fa<a:
               ff = a
               x +=a-fa
          elif fa>b:
               ff = b
               x +=fa-b
          else:
               ff = fa

          x +=(tb-ta)+abs(fb-ff)

     print(x)