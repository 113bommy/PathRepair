#Sum_of_Round_Numbers
testCases=int(input())
res=[]
while testCases:
    s = input()
    counter = 0
    ans=[]
    a={}
    for i in range(1, len(s)):
        if int(s[i]) > 0:
            counter += 1
            x = s[i]
            for i in range(len(s)-i-1):
                x += '0'
            ans.append(int(x))
    a[counter]=ans
    res.append(a)
    testCases -= 1

for i in res:
    for j in i:
        print(j)
        print(*i[j], sep=" ")
