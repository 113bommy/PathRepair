# Greg's Workout
def workout(arr):
    chest = 0
    biceps = 0
    back = 0
    flag = 1
    for i in arr:
        if flag == 1:
            chest += i
            flag +=1
        elif flag == 2:
            biceps += i
            flag += 1
        elif flag == 3:
            back += i
            flag = 0
    big = max(chest, biceps, back)
    if chest == big:
        return "chest"
    elif biceps == big:
        return 'biceps'
    return 'back'




n = int(input())
ar = list(map(int, input().rstrip().split()))
print(workout(ar))