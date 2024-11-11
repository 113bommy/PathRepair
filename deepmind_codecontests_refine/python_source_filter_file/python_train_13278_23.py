n = int(input())
if(n == 1): print("I hate it")
elif(n==2): print("I hate that I love it")
elif(n % 2 == 0 and n > 2):
    print("I hate that I love that " * ((n-2)//2) + "I hate that, I love it") 
elif(n % 2 !=0 and n > 2):
    print("I hate that I love that " * ((n-1)//2) + "I hate it")