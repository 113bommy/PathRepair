while(True):
  h,w=map(int,input().split())
  if h==0 and w==0:
    break
  rect='#'*w+'\n'
  rect+=('#'+'.'*(w-2)+'#\n')*(h-2)
  rect='#'*w+'\n'
  print(rect)