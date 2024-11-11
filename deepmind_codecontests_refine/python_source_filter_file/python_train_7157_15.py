landscape=input()
pos=0
for i in range(len(landscape)-3):
    temp=landscape[i:i+3]
    if "A" in temp and "B" in temp and "C" in temp:
        print("YES")
        quit()
    pos+=1
print("NO")