n = int(input())
if(n%7==0):
    print(str(int(n/7*2)) +  " " + str(int(n/7*2)))
else:
    if(n%7==6):
        mx = (int(n//7)+1)*2
        mn = (int(n//7))*2 + 1
    elif(n%7==1):
        mx = (int(n//7))*2
        mn = (int(n//7))*2 + 1
    else:
        mx = (int(n//7)+1)*2
        mn = (int(n//7))*2 
    print(str(mn) + " " + str(mx))