n = int(input())
s = input()

number_A = 0
number_D = 0
for c in s:
    if c is'A':
        number_A +=1
    else:
        number_D +=1
if number_A > number_D:
    print('Anton')      
elif number_D > number_D:
    print('Danik') 
else:
    print('Friendship')             