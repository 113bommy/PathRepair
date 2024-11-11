inputnumber,interval=list(map(int,input().split()))
elementara=list(map(int,input().split()))
answer=0
loop1=0
for i in range(len(elementara)):
    if i<(min(interval,(inputnumber-interval))):
        answer+=(elementara[i])*(i+1)
        #print(elementara[i],i+1)
    elif i>((len(elementara))-min(interval,(inputnumber-interval))-1):
        answer += (elementara[i]) * ((len(elementara)-i))
        #print(elementara[i],(len(elementara)-i))
    else:
        answer+=(min(interval+1,(inputnumber-interval+1))*(elementara[i]))
        #print(elementara[i],min(interval,(inputnumber-interval))+1)
#print(answer)
if inputnumber==1 or interval==1:
    print('{0:.7f}'.format(answer / (inputnumber)))
else:
    print ('{0:.7f}'.format(answer/(inputnumber-interval+1)))