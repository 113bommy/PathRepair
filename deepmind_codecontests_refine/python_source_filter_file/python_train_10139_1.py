candies,n=input().split(" ")
candies=int(candies)
n=int(n)
answer=[]
while(n>0):
    temp=int(candies/n)
    answer.append(temp)
    n-=1
    candies=candies-temp
for i in answer:
    print(answer[i], end=" ")
 

    