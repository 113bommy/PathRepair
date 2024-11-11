user_input=int(input())
candies=user_input**2

candy_pairs=[]

for i in range(candies//2):
    candy_pairs.append([i,candies-i])

per_person=len(candy_pairs)//user_input

number=0
for i in range(user_input):
    for j in range(per_person):

        print(candy_pairs[number][0],candy_pairs[number][1],'',end='')
        number += 1

    print('')
