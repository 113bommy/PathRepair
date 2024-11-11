n = int(input())
string = input()
anton=string.count('A')
danik=string.count('D')
if anton > danik:
    print("Anton")
elif anton == danik:
    print("Friendship")
else:
    print("Danik")
