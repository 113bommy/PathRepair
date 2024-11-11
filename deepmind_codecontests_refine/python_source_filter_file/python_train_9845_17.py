n = int(input())
string = input()
anton=string.count('A')
dalvik=string.count('D')
if anton > dalvik:
    print("Anton")
elif anton == dalvik:
    print("Friendship")
else:
    print("Dalvik")
