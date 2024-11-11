
def fun(n, v ,my):
      n_v=sum(v)+my
      majo=(n_v//2)+ 1
      if majo <= my:
            print(1,"\n1")
            return 
      oth="1"
      final=my
      x=1
      for i in range(n):
            if v[i]*2 <= my:
                  final+=v[i]
                  oth+=" "+str(i+2)
                  x+=1
            if final >= majo:
                  break
      if x==1 or final <majo:
            print(0)
      else :
            print("{}\n{}".format(x,oth) )
      return 
                               


x=int(input())
l=list(map(int, input().split()))
annu=l.pop(0)
fun(x-1,l,annu)