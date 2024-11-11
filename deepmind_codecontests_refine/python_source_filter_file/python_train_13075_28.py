
def CalcDif(input:str):
    global answer, l1
    counter =0
    l2= []
    for i in range (0,input.__len__()):
        if input[i]!=s[i]:
            counter+=1
            l2.append(int(i+1))
    if counter < answer:
        l1= l2
        answer = counter


input()
s = input()
t = input()

answer = t.__len__()
l1 = []
for i in range(0,t.__len__()-s.__len__()+1):
    CalcDif(t[i:i+s.__len__()])

print(answer)
for i in l1:
    print(i, end=" ")