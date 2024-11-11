while(True):
  h,w=map(int,input().split())
  if h==0 and w==0:
    break
  rect=('#'*w+'\n')*h
  print(rect+'\n')