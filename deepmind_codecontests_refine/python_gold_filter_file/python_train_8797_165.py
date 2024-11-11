user_input = int(input())
list = [5,4,3,2,1]
count = 0
for i in list:
    if user_input % i == 0:
        count += user_input // i
        break
    else:
        count += user_input // i
        user_input = user_input % i
print(count)
