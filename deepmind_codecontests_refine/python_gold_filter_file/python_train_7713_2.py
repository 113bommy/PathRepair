n = int(input())
string = str(n)

length = len(string)
count = 0
if length == 1 :
    print(0)


while length > 1 :
    sum = 0
    for i in range(length):
        sum += int(string[i])
    string2 = str(sum)
    length = len(string2)
    string = string2
    count +=1
    if length == 1 :
        print(count)
        break
