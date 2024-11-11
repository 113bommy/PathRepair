n=input()
n=list(n)
a='aeiou'
if(len(n)==1):
    if(n[0]!='n' and n[0] not in a):
        print("NO")
    else:
        print("YES")
        exit()
else:
    for i in range(len(n)-1):
        if(n[i] not in a and n[i]!='n'):
            if(n[i+1] not in a):
                print("NO")
                exit()
        if(n[len(n)-1] not in a or n[len(n)-1]!='n'):
            print("NO")
            exit()
    print("YES")