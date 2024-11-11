g = int(input())
gf = ''
for i in range(g+1, 9000):
     gs = str(i)
     if len(set(gs)) == 4 :
          gf = gs
          break
print(gf)
