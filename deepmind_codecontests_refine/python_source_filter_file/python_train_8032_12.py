h,w=map(int,input().split())
arr=[input() for _ in range(h)]
cnt_center=0
pos_center_x=0
pos_center_y=0
cnt_plus=0
cnt_black=0
if h>=3 and w>=3:
  for i in range(1,h-1):
    for j in range(1,w-1):
      if arr[i][j]=='*':
        if arr[i-1][j]=='*' and arr[i+1][j]=='*' and arr[i][j-1]=='*' and arr[i][j+1]=='*':
          cnt_center+=1
          pos_center_y=i
          pos_center_x=j
  if cnt_center!=1:
    print('NO')
  else:
    for i in range(pos_center_x-1,-1,-1):
      if arr[pos_center_y][i]=='*':
        cnt_plus+=1
      else:
        break
    for i in range(pos_center_x+1,w):
      if arr[pos_center_y][i]=='*':
        cnt_plus+=1
      else:
        break
    for i in range(pos_center_y-1,-1,-1):
      if arr[i][pos_center_x]=='*':
        cnt_plus+=1
      else:
        break
    for i in range(pos_center_y+1,h):
      if arr[i][pos_center_x]=='*':
        cnt_plus+=1
      else:
        break
    for i in range(h):
      for j in range(w):
        if arr[i][j]=='*':
          cnt_black+=1
    if cnt_plus==cnt_black:
      print('YES')
    else:
      print('NO')
else:
  print('NO')