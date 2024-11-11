length=int(input())
count1=int(0)
count2=int(0)
count3=int(0)
count4=int(0)
string=input()
for i in range(0,length):
    if i%2==0:
        if string[i]!='r':
            count1+=1
        elif string[i]!='b':
            count2+=1
    else:
        if string[i]=='r':
            count3+=1
        elif string[i]=='b':
            count4+=1
moves1=int(max(count1,count3))
moves2=int(max(count2,count4))
answer=int(min(moves1,moves2))
print(answer)