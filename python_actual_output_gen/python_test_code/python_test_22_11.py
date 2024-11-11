_, k = map(int, input().split())
participants = list(filter(
    lambda x: x<5 and x<k and x+k<=5,  map(int, input().split())))
print(len(participants)// 3)
