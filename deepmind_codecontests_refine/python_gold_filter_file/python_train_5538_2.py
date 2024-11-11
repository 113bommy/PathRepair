import sys
input = sys.stdin.readline

q=int(input())

for testcases in range(q):
    h,n=map(int,input().split())
    P=list(map(int,input().split()))
    P.append(-10)

    NOW=h
    ANS=0
    ind=1

    while NOW>=3:
        #print(NOW,ind,ANS)
        if P[ind]<NOW-1:
            NOW=P[ind]+1
            continue

        if P[ind]==NOW-1 and P[ind+1]==NOW-2:
            NOW-=2
            ind+=2
            continue

        if P[ind]==NOW-1 and P[ind+1]!=NOW-2:
            NOW-=2
            ind+=1
            ANS+=1


    print(ANS)
            
        
        

    
