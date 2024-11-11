import sys
first = input()
second = input()

if len(first) != len(second):
    print("NO")
    exit()

count = 0 
index = []  
for i in range(len(first)):
    if first[i] != second[i]:
        count += 1 
        index.append(i) 

if count > 2 or count < 2:
    print("NO")
else:
    if first[index[0]] != first[index[1]]:
        if first[index[0]] == second[index[1]] and first[index[1]] == second[index[0]] :
            print("YES")
        else:
            print("NO")
    else:
        print("NO")



