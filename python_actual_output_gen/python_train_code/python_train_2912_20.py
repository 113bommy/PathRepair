y = str(input())
for x in range(int(y)+1,9001):
    new_str = ""
    non_str = ""
    for i in str(x):
        if i not in new_str:
            new_str += i
        else:
            non_str += i
    if len(non_str) == 0:
        print(new_str)
        break
    