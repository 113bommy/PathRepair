num = input()
num = num.split()
n = int(num[0])
x = int(num[1])
ip = input()

myDict = {}
ch = 'a'
for i in range(1,27):
    myDict.update({ch:i})
    ch = chr(ord(ch) + 1)
myList = []
for c in ip:
    myList.append([c,myDict[c]])

myList.sort(key = lambda x: x[1])
sum = 0
prev = myList[0][1]
sum += prev
count = 1
done = False
print(n)
if count!= x:
    for i in range(1,n):
        #print("LOOP" + str(i))
        if prev + 1 == myList[i][1] or prev == myList[i][1]:
            #print("PASS" + str(myList[i][1]))
            pass
        else:
            #print("ELSE" + str(myList[i][1]))
            count += 1
            sum += myList[i][1]
            prev = myList[i][1]
            if count == x:
                done = True
                print(sum)
                break
elif count == x:
    if not done:
        print(sum)
if count != x:
    print(-1)