feel1="I hate that I love that"
feel2="I hate that I love it"
n=int(input())

if n>=1 and n<=100:
    if n==1:
        print("I hate it")
        
    elif n==2:
        print(feel2)
    elif n%2==0:
        print(feel1*(n//2-1),end=" ")
        print(feel2)
        
    else:
        print(feel1*(n//2),end=" ")
        print("I hate it")
        