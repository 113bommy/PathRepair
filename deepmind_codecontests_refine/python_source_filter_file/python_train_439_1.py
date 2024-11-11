for _ in range(int(input())):
  a,b=map(int,input().split())
  c=0
  if (a==0 or b==0 ) or (a<2 and b<2):
    print('0')
  elif  max(a,b)>(min(a,b)*2)-2:
    print(min(a,b))
  else:
    print(int((a+b)/3))
     #while(True):
    # :
     # print(c)
      #break;
    #else:
     # t1=max(a,b)-2
      #t2=min(a,b)-1
      #print(t1,t2)
      #a=t1
      #b=t2
      #c+=1