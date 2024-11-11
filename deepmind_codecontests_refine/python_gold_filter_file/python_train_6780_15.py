string = input()
length = int(input())
counter = 0
counter_z = 0
counter_v = 0
for elem in string:
    if elem == '*':
        counter_z += 1
    elif elem == '?':
        counter_v += 1
diff = length - (len(string) - counter_z - counter_v)
#print(diff)
res = 0
if diff <= 0:
    if counter_z + counter_v >= abs(diff):
        res = abs(diff)
        i = 0
        while i < len(string):
            if (i + 1 < len(string)) and (string[i + 1] == '*' or string[i + 1] == '?') and res > 0:
                res -= 1
                i += 1
            else:
                if string[i] == '*' or string[i] == '?':
                    i += 1
                else:
                    print(string[i], end = '')
                    i += 1
    else:
        print('Impossible')
else:
    if counter_z > 0:
        res = abs(diff)
        i = 0
        used = 0
        while i < len(string):
            if string[i] == '*' and not used:
                string = string[: i] + string[i - 1] * diff + string[(i + 1):]
                used = 1
            elif string[i] ==  '?' or string[i] == '*' :
                i += 1
            else:
                print(string[i], end = '')
                i += 1
    else:
        print('Impossible')
                  
             
