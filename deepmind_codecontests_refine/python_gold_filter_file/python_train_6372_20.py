def substr(num,word,letters):
    letters=letters.split(" ")
    sum=0
    length=int(num.split(" ")[0])
    index=[]
    val=0
    index.append(0)
    for i in range(length):
        if letters.count(word[i])==0 :index.append(i+1)
    index.append(length+1)
    for i in range(len(index)-1):
        sum+= (index[i+1]-index[i]-1)*(index[i+1]-index[i])/2
    print(int(sum))

def runner():
    num=input()
    word=input()
    letters=input()
    substr(num,word,letters)

runner()