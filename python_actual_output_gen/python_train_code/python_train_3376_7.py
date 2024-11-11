for i in range(int(input())):
    n=int(input())
    string=input()
    string2=""
    temp=string
    output=1
    for k in range(1,n+1):
        if k%2==0:
            string2=string[k-1]+string[k:]+string[:k-1]
        else:
            string2=string[k-1]+string[k:]+string[:k-1][::-1]
        
        if string2<temp:
            temp=string2
            output=k
    print(temp)
    print(output)