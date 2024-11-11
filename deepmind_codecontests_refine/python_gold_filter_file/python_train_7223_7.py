f, r, unknow="Freda's", "Rainbow's", "OMG>.< I don't know!"
answer=[]
n=int(input())
for i in range(n):
    s=input()
    if s[0:5]=="miao.":
        if s[-5:]=="lala.": answer.append(unknow)
        else: answer.append(r)
    elif s[-5:]=="lala.": answer.append(f)
    else: answer.append(unknow)
for i in answer: print(i)
