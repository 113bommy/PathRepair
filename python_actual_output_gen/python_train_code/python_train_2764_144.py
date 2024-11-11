x = input()
list1 = list(map(int,input().split()))
count = 0
for i in range(0, len(list1)):
    y = float(list1[i]/100)
    count+= y
print(count/len(list1))
