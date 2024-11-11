string = input()
pivot = string.index("^")
#print(pivot)
sm = 0
for index in range(0,len(string)):
    if (string[index:index+1] != "^" and string[index:index+1] != "="):
        sm += (pivot-index)*int(string[index:index+1])
#print(sm)
if sm < 0:
    print("right")
elif sm > 0:
    print("left")
else:
    print("balance")