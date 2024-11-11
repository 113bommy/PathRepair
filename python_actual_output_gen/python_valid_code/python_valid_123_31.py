def answer():
    a = int(input())
    c=[]
    while a:
        d = input().split()
        d = [int(x) for x in d]
        c.append(d)
        a-=1
    i=0
    #print(c)
    read=int(input())
    while i<len(c):
        if c[i][0]<=read and read<c[i][1]:
            print(len(c)-i)
            break
        i+=1

        
    
answer()