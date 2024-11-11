test_cases = int(input())
test = test_cases
data = []
while test_cases > 0:
    data.append(input().split())
    test_cases -= 1

for i in range(0,test):
    if int(data[i][0]) > int(data[i][1]):
        if int(data[i][0]) - int(data[i][1]) % 2 == 0:
            print(1)
        else:
            print(2)
    elif int(data[i][0]) < int(data[i][1]):
        if int(data[i][0]) - int(data[i][1]) % 2 == 1:
            print(1)
        else:
            print(2)
    else:
        print(0)
