from math import ceil
for _ in range(int(input())):
    #n= int(input())
    #li= list(map(int, input().strip().split()))
    li= input()
    temp=0
    freq=[]
    i=0
    while i<len(li):
        temp=0
        test=0
        while(i<len(li) and li[i]=="1"):
            temp+=1
            i+=1
            test=1
        if(test==0):
            i+=1
        if(temp>0):
            freq.append(temp)

    print(freq)
    freq.sort(reverse=True)
    ans=0
    for i in range(0,len(freq),2):
        ans+=freq[i]
    print(ans)