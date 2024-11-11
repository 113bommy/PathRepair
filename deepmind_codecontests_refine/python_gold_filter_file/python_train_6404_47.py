n1 = input()
n2 = input()
 
result = []
i = 0
 
 
while(i != len(n1)):
    if(n1[i] == n2[i]):
        result.append(0)
    else:
        result.append(1)
    i += 1
for i in result:
    print(i,end = "")
