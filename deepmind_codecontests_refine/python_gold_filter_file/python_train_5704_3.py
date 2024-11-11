def main():
  _,*s=open(0)
  b,q='.'*101,range(101)
  for i,s in enumerate(s):
    a=[]
    for x,y,z,c in zip(b,'.'+s,s,q):
      c+=x=='.'>z
      i+=y=='.'>z
      if i>c:i=c
      a+=i,
    b,q=s,a
  print(a[-2])
main()