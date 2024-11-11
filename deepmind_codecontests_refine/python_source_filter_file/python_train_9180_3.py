n = int(input().strip())
s= input().strip()
ss= 0
mina = 0
ti = 0
for k in range(len(s)):
    if(s[k] == "("):
        ss+=1
    else:
        ss-=1
    if(ss<0):
        ti = k+1
        ss = 0
s=s[ti:]+s[:ti]
ss= 0
for k in range(len(s)):
    if(s[k] == "("):
        ss+=1
    else:
        ss-=1
    if(ss<0):
        print(0)
        print(1,1)
        break
else:
    if(ss == 0):
      pre=[0 for k in range(len(s))]
      for k  in range(len(s)):
          if (s[k] == "("):
              ss += 1
          else:
              ss -= 1
          pre[k] = ss
      tt = 0
      a =(1,1)
      for k in range(0,len(s)):
          if(pre[k] == 0):
              tt+=1
      maxi= tt
      g =0
      gg =0
      while(gg<len(s)):
          if(pre[gg] == 0):
                  if(gg != g+1):
                      yy = g+1
                      y = g+1
                      q = 0
                      while(yy<gg):
                          if(pre[yy] == 1):
                              if(yy !=y+1):
                                  rr = y+1
                                  r  = y+1
                                  h = 0
                                  while(rr<yy):
                                      if(pre[rr] == 2):
                                          h+=1
                                      rr+=1
 
                                  if(tt+h+1>maxi):
                                      maxi = tt + h + 1
                                      a=(y,yy)
                              q+=1
                              y = yy+1
                              yy = y
                          else:
                              yy+=1
 
                      if (q + 1 > maxi):
                          maxi = q+1
                          a = (g, gg)
                  g= gg+1
                  gg= g
          else:
               gg+=1
      print(maxi)
      print((a[0]+ti)%len(s)+1,(a[1]+ti)%len(s)+1)
 
 
 
 
    else:
        print(0)
        print(1,1)