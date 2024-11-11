import sys
pers=[]
sum=0




for line in sys.stdin:
    if line[0]=="+":
        pers.append(line[1:len(line)])
    elif line[0]=="-":
        pers.remove(line[1:len(line)])
    else:
        str=len(line)-line.find(":")
        sum=sum+str*len(pers)
print(sum)

