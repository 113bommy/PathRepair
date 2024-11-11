power = 0

n = int(input())
powers = [ int(x) for x in (input().split(' ')) ]
alisa_move = input()



def power_at(i,powers):
    p = powers[i]
    return p
    


move = list(alisa_move)
move1 = []
move1.extend(reversed(list(alisa_move)))

p_max = 0
for i in range(0,n):
    if move[i] == 'B':
        p_max+=power_at(i,powers)


p_temp = p_max
for i in range(0,n):
    if move[i] == 'A':
        move[i] = 'B'
        p_temp += power_at(i,powers)
        if (p_max < p_temp):
            p_max = p_temp
    elif move[i] == 'B':
        move[i] = 'A'
        p_temp -= power_at(i,powers)
        

powers1=[]
powers1.extend(reversed(powers))



p_temp=0
for i in range(0,n):
    if move1[i] == 'B':
        p_temp+=power_at(i,powers)



for i in range(0,n):
    if move1[i] == 'A':
        move1[i] = 'B'
        p_temp += power_at(i,powers1)
        if (p_max < p_temp):
            p_max = p_temp
    elif move1[i] == 'B':
        move1[i] = 'A'
        p_temp -= power_at(i,powers1)
            
print(p_max)