dict={"q":9,"Q":9,"r":5,"R":5,"b":3,"B":3,"n":3,"N":3,"P":1,"p":1}
ans={"k":0,"K":0,"r":0,"R":0,"b":0,"B":0,"n":0,"N":0,"P":0,"p":0}
#print(dict["r"]+2)
# print(ans)
black,white=0,0
for i in range(8):
    a=input()
    for j in range(8):
        # ans[a[j]]=ans[a[j]]+dict[a[j]]
        if a[j]=="q":
            black+=dict["Q"]
        if a[j]=="r":
            black+=dict["r"]
        if a[j]=="b":
            black+=dict["b"]
        if a[j]=="n":
            black+=dict["n"]
        if a[j]=="p":
            black+=dict["p"]
        if a[j]=="K":
            white+=dict["q"]
        if a[j]=="R":
            white+=dict["r"]
        if a[j]=="B":
            white+=dict["b"]
        if a[j]=="N":
            white+=dict["n"]
        if a[j]=="P":
            white+=dict["p"]
# print(black,white)
if (black>white):
    print("Black")
elif(white>black):
    print("White")
else:
    print("Draw")