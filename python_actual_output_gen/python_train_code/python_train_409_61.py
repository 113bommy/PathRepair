#573_A

num = int(input())

inc = 0
let = 0

if num % 4 == 0:
    inc = 0
    let = "A"
elif num % 4 == 2:
    inc = 1
    let = "B"
elif num % 4 == 3:
    inc = 2
    let = "A"
else:
    inc = 0
    let = "A"
    
print(inc, let)
