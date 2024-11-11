money = 0
apples = 0
customers = []

num_customers, apple_price = [ int(x) for x in (input().split(' ')) ]


for i in range(0,num_customers):
    arg = input()
    customers.append(arg)



customers = reversed(customers)



for c in customers:
    if c == 'halfplus':
        money += (apples+0.5)*float(apple_price)
        apples = 2*apples+1
    elif c == 'half':
        money += (apples)*float(apple_price)
        apples = 2*apples

print(money)