def comp(s):
  a = s[0]
  res1 = 0
  res2 = 0
  if a=='a':
    res1 = 1
  elif a=='b':
    res1 = 2
  elif a=='c':
    res1 = 3
  elif a=='d':
    res1 = 4
  elif a=='e':
    res1 = 5
  elif a=='f':
    res1 = 6
  elif a=='g':
    res1 = 7
  elif a=='h':
    res1 = 8
  res2 = int(s[1])
  return (res1, res2)
    

def move(x1, y1, x2, y2, count, counter):
  if x1==x2 and y1==y2:
    print(count)
    for i in counter:
      print(i)
  elif x1<x2 and y1>y2:
    counter.append('RD')
    count+=1
    return move(x1+1, y1-1, x2, y2, count, counter)
  elif x1<x2 and y1==y2:
    counter.append('R')
    count+=1
    return move(x1+1, y1, x2, y2, count, counter)
  elif x1<x2 and y1<y2:
    counter.append('RU')
    count+=1
    return move(x1+1, y1+1, x2, y2, count, counter)
  elif x1>x2 and y1>y2:
    counter.append('LD')
    count+=1
    return move(x1-1, y1-1, x2, y2, count, counter)
  elif x1>x2 and y1==y2:
    counter.append('L')
    count+=y1
    return move(x1-1, y1, x2, y2, count, counter)
  elif x1>x2 and y1<y2:
    counter.append('LU')
    count+=y1
    return move(x1-1, y1+1, x2, y2, count, counter)
  elif x1==x2 and y1<y2:
    counter.append('U')
    count+=1
    return move(x1, y1+1, x2, y2, count, counter)
  else:
    counter.append('D')
    count+=1
    return move(x1, y1-1, x2, y2, count, counter)

s1 = input()
s2 = input()
move(comp(s1)[0], comp(s1)[1], comp(s2)[0], comp(s2)[1], 0, [])