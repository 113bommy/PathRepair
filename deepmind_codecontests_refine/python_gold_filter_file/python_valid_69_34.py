
#n = int(input())
 
a = []
i = 1

def similarity(xt):
  x = []
  while xt  != 0:
    x.append(xt % 10)
    xt = xt // 10
  x.reverse()
# 1024 1052
  res = -1
  for tw in a:
    ix = 0
    simil = 0
    for elx, el in enumerate(tw):
      incl = False
      while ix < len(x):
        if x[ix] == el:
          simil += 1
          incl = True
        ix += 1
        if incl:
          break
      if not incl or elx == len(tw) - 1  or ix == len(x):
        newRes = len(tw) + len(x) - 2 * simil
        if res == -1 or newRes < res:
          res = newRes
  return res


       
while i < 10 ** 18 + 1:
  t = []
  ti = i
  while ti  != 0:
    t.append(ti % 10)
    ti = ti // 10
  t.reverse()
  a.append(t)
  i = i * 2

n = int(input())
lst = []
for i in range(0, n):
    ele = int(input())
    print(similarity(ele))