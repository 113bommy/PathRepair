cases=int(input())

for single_case in range(cases):
    numbers_in_array=int(input())
    array=list(map(int,input().split()))
    odd_numbers=[i for i in range(2*numbers_in_array) if (array[i]%2)==0]
    even_numbers=[i for i in range(2*numbers_in_array) if (array[i]%2)==1]
    for j in range(numbers_in_array - 1):
        if(len(odd_numbers)>1):
            print(odd_numbers[0], odd_numbers[1])
            del odd_numbers[:2]
        elif(len(even_numbers)>1):
            print(even_numbers[0], even_numbers[1])
            del even_numbers[:2]
