length=int(input())
start=input()
slist=[ord(char)-97 for char in start]
end=input()
elist=[ord(char)-97 for char in end]
result=[]
weirdnumber=0
for i in range(0,length,1):
    dif=((elist[i]+slist[i])/2)+weirdnumber
    weirdnumber=0
    if int(dif)!=dif:
        result.append(int(dif))
        weirdnumber=13
    else:
        result.append(int(dif))
for i in range(length-1,-1,-1):
    if result[i]>26:
        r=result[i]//26
        result[i]-=r*26
        result[i-1]+=r
actualresult=''
for char in result:
    thing=(chr(97+char))
    if thing=="{":
        actualresult+=('a')
    else:
        actualresult+=(chr(97+char))
print(actualresult)