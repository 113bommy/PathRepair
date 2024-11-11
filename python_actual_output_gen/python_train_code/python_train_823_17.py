
a=input()
b=input()
c=input()
if((a=="rock" and b=="rock" and c=="paper") or (a=="scissors" and b=="scissors" and c=="rock") or (a=="paper" and b=="paper" and c=="scissors")):
    print("S")
elif((a=="rock" and c=="rock" and b=="paper") or (a=="scissors" and c=="scissors" and b=="rock") or (a=="paper" and c=="paper" and b=="scissors")):
    print("D")
elif((c=="rock" and b=="rock" and a=="paper") or (c=="scissors" and b=="scissors" and a=="rock") or (c=="paper" and b=="paper" and a=="scissors")):
    print("F")
else:
    print("?")
