def sort(letter, n):
    number = []
    for i in range(2,n+2):
        number.append(i)
    for i in range(1, n):
        for j in range(n - i):
            if letter[j] < letter[j + 1]:
                number[j], number[1 + j] = number[1 + j], number[j]
                letter[j], letter[1 + j] = letter[1 + j], letter[j]

    return letter, number
def report(letter,number):
    i=-1
    z=0
    for j in range(len(letter)):
        if letter[j]!=0 and j+i<len(letter)-2:
            print(number[j],number[j+1])
            for a in range(letter[j]-1):
                i += 1
                if i+j==len(letter) or number[len(letter)-i-1]==number[j] :
                    z=1
                    break
                print(number[j],number[len(letter)-i-1])

        if z==1:
            break


n = int(input())
lettter = list(map(int, input().split()))
summa = 0
for el in lettter:
    summa += el
if summa < (n-1) or lettter[0] == 0:
    print(-1)
else:
    s=lettter[0]
    letter, number = sort(lettter[1:], n-1)
    letter.insert(0,s)
    print(n-1)
    report(letter,[1]+number)