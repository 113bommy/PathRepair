t=int(input())
while t>0:
    b=input()
    c=0
    a=''
    while c<len(b)-1:
       if b[c]!=b[c+1]:
              a=a+b[c]
       else:
          a=a+b[c]
          c=c+1
       c=c+1
    a=a+b[len(b)-1] 
    print(a,end='')
    t=t-1
   