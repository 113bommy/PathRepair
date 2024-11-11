password = input()
numWords = int(input())

front = False
back = False

for _ in range(numWords):
    word = input()

    if word == password:
        front = True
        back = True
        
    if word[0] == password[1]:
        front = True
    if word[1] == password[0]:
        back = True

if back == True and front == True:
        print('YES')
else:
    print('NO')