n=int(input())
s=input()
i=s.count('8')
if(s.count('8')==0):
    print(0)
else:
    while(i>=0):
        if (n-i)>=10*i:
            print(i)
            break
        else:
            i-=1
    
