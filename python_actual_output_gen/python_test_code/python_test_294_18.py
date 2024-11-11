n=int(input())
for i in range(n):
  a=input()
  a=list(a)
  r=0
  y=[]
  for i in range(len(a)):
      if a[i]=='1':
          x=0
          for j in range(i+1,len(a)):
              if a[j]=='0':
                  x+=1
              if a[j]=='1':
                  break
          y.append(x)
  if a[len(a)-1]!='1' and len(y)>1:
       print(sum(y)-y[len(y)-1])
  else:
       print(sum(y))
          
