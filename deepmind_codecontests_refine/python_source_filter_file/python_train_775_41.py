num1 = input()
a = []


def get_the_data(count, num, arr):
    for i in range(0, len(num)):
        if num[i] == ' ':
            arr.append(int(num[count:i]))
            count = i+1
        elif i == len(num)-1:
            arr.append(int(num[count:len(num)]))
    return arr


arr1 =  get_the_data(0, num1,  a)
player1 = arr1[0]
player1_balls = arr1[2]
player2 = arr1[1]
player2_balls = arr1[3]
i = 1
while player1 >  0  or player2 > 0:
    if i%2 == 1:
        player1 -= 1
    else:
        player2 -= 1
    i += 1
print(i)
if i%2 == 1:
    print("Second")
else:
    print("First")



''''
if player1 - player2_balls <= 0:
            player2 -= player2_balls
        else:s

'''