n=int(input())
for item in range(n):
    a=int(input())
    for i in range(1,181):
        p=1
        if a%(180/i)==0 and (180/i)*(i-2)>=a:
            print(i)
            p=0
            break
    if p==1:
        print(-1)
        
        
