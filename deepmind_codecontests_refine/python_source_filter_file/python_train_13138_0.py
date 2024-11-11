def prefix(lsa,n):
    index=0
    i=1
    while i<n:
        if s[i]==s[index]:
            lsa[i]=index+1
            i+=1
            index+=1
        else:
            if index==0:
                lsa[i]=0
                i+=1
            else:
                index = lsa[index-1]
                     
s = input()
n = len(s)
lsa=[0]*(n)
prefix(lsa,n)
#print(lsa)
if lsa[-1]==0:
    print("Just a legend")
else:
    for i in range(n-1):
        if lsa[i]==lsa[-1]:
            print(s[:lsa[i]])
            exit()
    if(lsa[lsa[-1]]==0):
        print("Just a legend")
    else:
        print(s[:lsa[lsa[-1]]])

    
