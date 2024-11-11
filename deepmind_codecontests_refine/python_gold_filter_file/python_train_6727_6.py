i = input()
alphabet= [
  #  "A",
    "B",
    "C",
    "D",
 #   "E",
    "F",
    "G",
    "H",
  #  "I",
    "J",
    "K",
    "L",
    "M",
    "N",
  #  "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
 #   "U",
    "V",
    "W",
    "X",
    "Y",
    "Z"
]
res=''
flag=0
for j in range(len(i))  :
    if flag>0:
        flag-=1
        res+=i[j]  
        continue
    if j!=0 and j!=len(i)-1:
        if (i[j].upper() in alphabet and i[j-1].upper() in alphabet and i[j+1].upper() in alphabet) and not (i[j-1]==i[j] and i[j]==i[j+1]):
            res+=(i[j]+' ')
            flag=1
            continue
        else:
            res+=i[j]
    else: res+=i[j]
print(res)