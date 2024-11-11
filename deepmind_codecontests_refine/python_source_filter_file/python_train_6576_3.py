n=int(input())
def isSubSequence(string1, string2, m, n): 
    # Base Cases 
    if m == 0:    return True
    if n == 0:    return False
  
    # If last characters of two strings are matching 
    if string1[m-1] == string2[n-1]: 
        return isSubSequence(string1, string2, m-1, n-1) 
  
    # If last characters are not matching 
    return isSubSequence(string1, string2, m, n-1) 
for x in range(n):
    s=input()
    t=input()
    p=input()
    k=s+p
    listk=[]
    listt=[]
    flag=0
    for x in range (0,26):
        listk.append(0)
        listt.append(0)
    for x in range(len(k)):
        listk[ord(k[x])-ord("a")]+=1
    print(listk)
    for x in range(len(t)):
        listt[ord(t[x])-ord("a")]+=1
    print(listt)
    if isSubSequence(s,t,len(s),len(t)):
        for x in range(26):
            if (listk[x]<listt[x]):
                flag=1
                break
        if flag==1:
            print("No")
        if flag==0:
            print("Yes")
    else:
        print("No")
    
    
