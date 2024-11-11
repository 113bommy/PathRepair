n = int(input())
k = 1
otv = ""
kolvo = 0
st = ""
while k<=n:
    ryad = input()
    if "OO" in ryad and kolvo < 1:
        st = ryad.replace("OO","++")
        otv = otv + st + "\n"
        kolvo+=1
    else:
        otv = otv + ryad + "\n"
    k+=1
if kolvo == 0:
    print("NO")
else:
    print("YES")
    print(otv)
