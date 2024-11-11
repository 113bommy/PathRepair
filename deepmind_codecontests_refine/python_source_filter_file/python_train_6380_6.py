for _ in " "*int(input()):
  p,q=map(int,input().split())
  if p%q:
    print(p)
  else:
    lst=[]
    i=2
    while i*i<=q:
      if not q%i:
        lst.append(i)
        if i!=q//i: 
          lst.append(q//i)
      i+=1
    lst.append(q)
    num=1
    for i in lst:
      ele=p
      while not ele%i:
        ele//=i
        if ele%q:
          num=ele
          break
    print(num)