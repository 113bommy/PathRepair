T=int(input())
for i in range(T):
    N=int(input())
    numbers=list(map(lambda x: int(x), input().split(" ")))
    #print(numbers)
    minimum_operations_needed=0

    # all 0 to 1
    for j in range(len(numbers)):
        if numbers[j]==0:
            numbers[j]=1
            minimum_operations_needed+=1
    
    if sum(numbers)!=0:
        print(minimum_operations_needed)

    else:
        minimum_operations_needed+=1
        print(minimum_operations_needed)