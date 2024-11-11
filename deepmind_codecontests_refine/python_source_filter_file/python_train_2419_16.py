import string

def moves(cases):
    a=cases[0]
    b=cases[1]
    m=0
    
    div=a/b
    rest=a%b
    
    if rest==0:
        return m
    else:
        div=int(div)
        div+=1
        c=b*div
        m=c-b
        return m
    

for i in range(int(input())):
    cases=input().split(" ")
    for j in range(len(cases)):
        cases[j]=int(cases[j])

    print(moves(cases))
    
    

