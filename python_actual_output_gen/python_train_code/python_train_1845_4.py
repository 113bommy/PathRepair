for j in range(int(input())):
       li= list(map(int,input().split()))
       count = 0
       for j in li:
          if j%2!=0:
             count+=1
       if count==2 :
          print("no")
       elif count<=1 and count ==4:
          print("yes")
       elif count == 3 and li[0]>=1 and li[1]>=1 and li[2]>=1 and li[3]>=1:
           print("yes")
       elif count == 3 and li[0] ==1 and li[1]==1 and li[2]==1 and li[3]==0:
          print("yes")
       else:
          print("no")
          
          
         
       