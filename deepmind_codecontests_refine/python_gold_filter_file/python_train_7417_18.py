t=int(input())
for p in range(0,t):
    s=input()
    s1=''
    j=0
    for i in s:
        if j%2==0:
            s1=s1+i
            #print(s1)
        j+=1
    #s1=s1.join(s[-1])
    #print(s[-2])
    print(s1+s[-1])