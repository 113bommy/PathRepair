i = int(input())
count = 1
while count <= i:
    inputstr1 = input()
    inputstr2 = input()
    count2 = 0
    while count2 < len(inputstr1):
        if inputstr2.find(inputstr1[count2]) == -1:
            print("NO")
            break
        elif count2 == len(inputstr1) - 1:
            print("YES")
            break
        count2 += 1
    count+=1



