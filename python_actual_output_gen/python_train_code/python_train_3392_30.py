num_citizens = int(input())

welfare = list(map(int, input().split()))
mayor = 0

for i in range(0, num_citizens):

    if(i == 0):
        mayor = welfare[0]
    else:
        if (welfare[i] > mayor):
            mayor = welfare[i]

print(mayor)

count_money = 0

for i in range(0, num_citizens):
    
    if(welfare[i] < mayor):
        count_money = (mayor - welfare[i]) + count_money

print(count_money)
