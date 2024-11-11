qaq= input()
Q, A, co= [], [],  0
for x in range(0, len(qaq)):
    if (qaq[x]=="A"): 
      A.append(x)
for i in A:
    co+=qaq[i:].count("Q")+qaq[: i].count("A")
print(co)
