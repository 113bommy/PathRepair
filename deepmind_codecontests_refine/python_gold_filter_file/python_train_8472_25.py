no,find = map(int,input().split())
if no%2==0:
    a=int(no/2)
    if find<=a:
        print(2*find-1)
    else:
        print(2*(find-a))
else:
    a=int((no/2)+1)
    if find<=a:
        print(2*find-1)
    else:
        print(2*(find-a))
    
 



    
