lines = []
for i in range(4):
    line = list(input())
    lines.append(line)

for i in range(3):
    for j in range(3):
        count_hash = 0
        count_dot = 0
        if lines[i][j] == "#":
            count_hash += 1
        else:
            count_dot+=1

        if lines[i+1][j] == "#":
            count_hash += 1
        else:
            count_dot+=1

        if lines[i][j+1] == "#":
            count_hash += 1
        else:
            count_dot+=1

        if lines[i+1][j+1] == "#":
            count_hash += 1
        else:
            count_dot+=1

            


        if count_hash > 2 or count_dot>2:
            print ("YES")
            exit()



print("NO")

