str1 = input()

arr = list(map(int, str1.split(":")))


if arr[0] == 23 and arr[1] >= 32:
    print("00:00")

elif arr[0] >= 6 and arr[1] <= 9:
    print("10:01")

elif arr[0] == 15 and arr[1] < 51:
    print(str1.split(":")[0]+":"+str1.split(":")[0][::-1])

elif arr[0] >= 15 and arr[0] <= 19:
    print("20:02")

elif arr[1] < int(str1.split(":")[0][::-1]):
    print(str1.split(":")[0]+":"+str1.split(":")[0][::-1])

else:
    print(str1[0]+str(int(str1[1]) + 1)+":"+str(int(str1[1]) + 1)+str1[0])


