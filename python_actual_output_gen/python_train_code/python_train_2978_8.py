num = int(input())
data = []

for i in range(0,num):
    l = input()
    t = str(input())
    data.append(t)

for i in range (0,num):
    for j in range(0,len(data[i])):
        if len(data[i]) > 11:
            if data[i][0] == '8':
                print("YES")
                break
            else:
                data[i] = data[i][1:]

        else:
            print("NO")
            break