"""
goodLetters = input()
template = input()

arr = []
for i in range(int(input())):
    arr.append(input())
"""
goodLetters = "a"
template = "ab"

arr = ["a"]

for q in arr:
    if len(template)-1 > len(q):
        print("NO")  
        continue
    elif '*' not in template and len(template) < len(q):
        print("NO")  
        continue   
    elif '*' not in template and len(template) > len(q):
        print("NO")  
        continue
    
    flag = True
    index = 0
    for letter in template:
        if letter == '?':
            if q[index] not in goodLetters:
                flag = False
        elif letter == '*':
            t = len(q) - len(template) + 1
            if t == 0:
                continue
            temp = q[index:index+t]
            for i in temp:
                if i in goodLetters:
                    flag = False
                    break
            index += len(temp)
            continue
        elif letter != q[index]:
            flag = False
        if not flag:
            break
        index += 1
    
    if flag:
        print("YES")
    else:
        print("NO")