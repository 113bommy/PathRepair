text=[]
Max=0
while 1:
    try:
        tmp=input()
        Max=max(Max,len(tmp))
        text.append(tmp)
    except:
        break
print('*'*(Max+2))
flag=True
for i in text:
    tmp=Max-len(i)
    if flag:
        Tmp=tmp//2
    else:
        Tmp=tmp-tmp//2
    print('*'+' '*Tmp+i+' '*(tmp-Tmp)+'*')
    if Tmp!=tmp//2: 
        flag=not flag
print('*'*(Max+2))
