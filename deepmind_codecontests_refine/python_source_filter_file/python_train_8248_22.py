cases = int(input())
for i in range(cases):
    line1 = int(input())
    line2 = input().split(' ')
    arr = []
    for a in line2:
        arr.append(int(a))
    if (len(arr) == 2):
        print(arr[0] ^ arr[1])
        continue
    
    elif (len(arr)%2 == 1):
        print(-1)
        continue
    pos_ans = []
    for b in range(len(arr)):
        ele1 = arr[b]
        for c in range(b+1,len(arr)):
            ele2 = arr[c]
            op = ele1 ^ ele2
            pos_ans.append(op)
    pos_ans.sort()
    counter = {}
    found = False
    for d in pos_ans:
        if (d in counter):
            counter[d] += 1
        else:
            counter[d] = 1
    
    for key in counter:
        value = counter[key]
        if (value == 4):
            found = True
            ans = key
            break
    if (found):
        print (ans)
    else:
        print (-1)