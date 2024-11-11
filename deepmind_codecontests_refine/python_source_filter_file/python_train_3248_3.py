n = int(input())
t = list(map(int,input().split(" ")))
sum_ =0
elements = set()
err_,events = False,0
result  = []
for index in range(n):
    element = t[index]
    if element >0 and element not in elements:

        elements.add(element)
        sum_+=element

    elif element <0 and -element in elements:
        sum_+=element
    else:
        err_=True
        break
    
    events+=1
    if sum_==0:
        result.append(events)
        events=0
        elements = set()   

if err_ or sum!=0:
    print(-1)
else:
    print(len(result))
    print(*result)   
        
