num=input()
stones=input()
conter=int(0)
for i in range (len(stones)-1):
    if stones[i]==stones[i+1]:
        conter+=1
print(conter)