
def check(l):
    chest = 0
    biceps = 0
    back = 0
    for i in range(0,2):
        if len(l) % 3 == 0:
            break
        l.append(0)

    for i in range(0,len(l)//3,3):
        chest += l[i]
        biceps += l[i+1]
        back +=l[i+2] 

    if chest > biceps and chest > back:
        return 'chest'
    elif biceps > chest and biceps > back:
        return 'biceps'
    else:
        return 'back'


t = int(input())
a = input().split()
b = map(int, a)
i_list = list(b)
print(check(i_list))



