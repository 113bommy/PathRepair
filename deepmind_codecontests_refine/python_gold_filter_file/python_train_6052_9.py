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
        countone+=2
        if(countone==5):
            countone = 1

