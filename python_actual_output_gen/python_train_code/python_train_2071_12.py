n,m = map(int, input().split())

sum = 0
 
for i in range(n + 1):
    sum += i
 
remainder = m % sum
 
for i in range(1, remainder + 1):
    remainder -= i
    if(remainder == 0):
        print(0)
        break
    elif(remainder < 0):
        print(remainder + i)
        break