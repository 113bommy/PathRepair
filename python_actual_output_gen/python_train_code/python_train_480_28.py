nbr= int(input())
list = []
for i in range(nbr):
    list.append(input())

for i in range(nbr):
    if list[i][len(list[i])-1] == "o":
        print("FILIPINO")
    elif list[i][len(list[i])-1] == "a":
        print("KOREAN")
    else:
        print("JAPONSE")
