number = input()
string = [i for i in input().split("W") if i]
# print([[str(len(string))+"\n"+" ".join(map(str,list((len(i) for i in string))[0:-1])),str(len(string))+"\n"+" ".join(map(str,list((len(i) for i in string))))][string[0] ==""],0]["B" not in ("".join(string))])
print(len(string),"\n"+("".join(list(str(len(i)) for i in string))))
