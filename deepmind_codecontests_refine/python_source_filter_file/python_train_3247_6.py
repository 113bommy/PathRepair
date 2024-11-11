def pipetype(i): # 1 for horizental and 2 for curved
  if(i=="1" or i=="2"):
    return 1;
  else:
    return 2;


def find_way2(arr,n):

  count=0
  row =0
  col=0
  prev_row=0
  prev_col=-1
  prev_state =1
  while(col <= n):
    #if(count==20):
     # break
    count+=1
    print(row,col)
    print(prev_row)
    prev_i=row
    prev_j=col


    if(col==n and row==0):
      return "NO"
    elif (col==n and row==1):
      return "YES"

    if (pipetype(arr[row][col])==1):
      if(row== prev_row):
        col+=1
      else:
        return "NO"
    elif (pipetype(arr[row][col])==2):
      if (row==0 and prev_row ==0):
        row+=1
      elif (row==0 and prev_row ==1):
        col+=1
      elif (row==1 and prev_row==0):
        col+=1
      elif (row==1 and prev_row==1):
        row-=1

    prev_row=prev_i
    prev_col=prev_j

  return "OK"



#2323216
#1615124



  
for i in range(int(input())):
  n = int(input())
  arr= [input()]
  arr.append(input())
  print(find_way2(arr,n))


#2323216
#1615124
