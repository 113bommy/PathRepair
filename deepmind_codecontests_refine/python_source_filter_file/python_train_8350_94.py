T = int(input())

Total = []
h = 0
m = 0
for i in range(T):

    temp = (input().split())

    if(len(temp) >= 1): 
        h = int(temp[0])*60

    if(len(temp) >= 2):
        m = int(temp[1])

    
    Total.append(1440-(h+m))

    h = 0
    m = 0

for i in range(5):
    print(Total[i])

