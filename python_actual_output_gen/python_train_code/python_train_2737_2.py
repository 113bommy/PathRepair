n, t = map(int, input().split())
Total_problem_solved=0
sum=0 
if t>235 :
  Total_problem_solved=0
else :
 remain =240-t
 for i in range(1,n+1,1):
    sum=sum+i*5
    if sum<= remain:
     Total_problem_solved+=1
    else : break
    
 print(Total_problem_solved)

		
