s = list(input())
countzero = 1
countone = 1
for j in range(len(s)):
    if(s[j]=='0'):
        print(3,countzero)
        countzero+=1
        if(countzero==5):
            countzero = 1
    else:
        print(1,countone)
        countone+=1
        if(countone==3):
            countone = 1

