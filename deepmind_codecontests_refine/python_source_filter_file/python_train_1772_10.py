def isCLKWISE(ph) : return not ((ph[-1][0] - ph[-3][0])*(- ph[-3][1] + ph[-2][1]) - (ph[-2][0] - ph[-3][0])*(- ph[-3][1] + ph[-1][1] ) < 0)
      
def ConvexHullScan(P) :
 P = sorted(P)
 phU = []
 phU.append(P[0])
 phU.append(P[1])
 for p in P[2:] :
  phU.append(p)
  if isCLKWISE(phU) : continue
  while(True)???:
   del phU[-2]
   try???:
    if isCLKWISE(phU) : break
   except IndexError : break
 phL = []
 phL.append(P[-1])
 phL.append(P[-2])
 for p in P[-3::-1] :
  phL.append(p)
  if isCLKWISE(phL) : continue
  while(True) :
   del phL[-2]
   try:
    if isCLKWISE(phL) : break
   except IndexError : break
 del phL[0]
 del phL[-1]
 ph = phU + phL
 return ph
  
n = range(int(input()))
P = [[int(x) for x in input().split()] for _ in n]
P = ConvexHullScan(P)
P.reverse()
print(len(P))
idx = min([[x[1][1],x[1][0],x[0]] for x in enumerate(P)])[2]
for p in P[idx:] + P[:idx] : print(p[0],p[1])