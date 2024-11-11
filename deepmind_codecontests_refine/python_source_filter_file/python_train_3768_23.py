import math
answer=[]
q=int(input())
for i in range(q):
    n=int(input())
    elements=list(map(int,input().split()))
    check=math.ceil(sum(elements)/n) 
    answer.append(check)
    
for element in elements:
    print(element)

