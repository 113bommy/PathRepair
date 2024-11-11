str = input()
flag = 0
for i in range (len(str)-2):
    if str[i:i+5] == "Danil" or str[i:i+5] == "Danil" or str[i:i+4] == "Olya" or str[i:i+5] == "Slava" or str[i:i+6] == "Nikita":
        flag = flag+1
if flag == 1:
    print("YES")
else: print ("NO")



