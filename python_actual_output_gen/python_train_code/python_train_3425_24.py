x=input()
x=x.replace(':'," ")
x=x.split()
y=input()
y=y.replace(':'," ")
y=y.split()

if ( x[0] == y[0] and int(x[1]) < int(y[1]) ):
      print( str(24-(int(y[0])-int(x[0]))-1)+":"+str(60-(int(y[1])-int(x[1]))))
else :
      a=int(x[0])-int(y[0])
      b=int(x[1])-int(y[1])
      if a < 0 :
            a=24+a
      if b >= 60 :
            a=a-1
            b=b-60
      f=0
      while f < 10 :
            if a == f :
                  a='0'+str(a)
            if b == f :
                  b='0'+str(b)
            f=f+1
      print(str(a)+":"+str(b))
