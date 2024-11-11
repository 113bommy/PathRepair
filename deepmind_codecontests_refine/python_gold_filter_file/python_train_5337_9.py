for j in range(int(input())):
       li= list(map(int,input().split()))
       count = 0
       for j in li:
          if j%2!=0:
             count+=1
       if count==2 :
          print("No")
       elif count<=1 or count ==4:
          print("Yes")
       elif count == 3 and li[0]>=1 and li[1]>=1 and li[2]>=1 and li[3]>=1:
           print("Yes")
       elif count == 3 and li[0] ==1 and li[1]==1 and li[2]==1 and li[3]==0:
          print("Yes")
       else:
          print("No")
          
          
         
       