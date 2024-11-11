while(1):
  
 sen1=input()
  
 if sen1=="-":
   break
 
 suff=int(input())
  
 for i in range(suff):
    h=int(input())
    sen1=sen1[h:]+sen1[:h]

 print(sen1)