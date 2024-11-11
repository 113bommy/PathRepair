string = input()
pivot = string.index("^")
print(pivot)
sum = 0
for index in range(0,len(string)):
    if (string[index:index+1] != "^" and string[index:index+1] != "="):
        sum += (pivot-index)*int(string[index:index+1])
print(sum)
if sum < 0:
    print("right")
elif sum > 0:
    print("left")
else:
    print("balance")