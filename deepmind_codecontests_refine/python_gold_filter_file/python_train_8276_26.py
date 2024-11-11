st=input()
ex=int(input())
h=int(st[:2])
m=int(st[3:])
time=h*60+m+ex
if (time//60)%24==24:
    print("00:",end="")
elif (time//60)%24<=9:
    print("0"+str((time//60)%24)+":",end="")
else:
    print(str((time//60)%24)+":",end="")
if time-(time//60)*60<=9:
    print("0",end="")
print(str(time-(time//60)*60))
