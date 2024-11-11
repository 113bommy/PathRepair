F=input()
M=input()
S=input()

a=1

if (F == "rock" and M == "scissors" and S == "scissors"):
    print("F")
elif (M == "rock" and F == "scissors" and S == "scissors"):
    print("F")
elif (S == "rock" and F == "scissors" and M == "scissors"):
    print("F")
    
elif (F == "paper" and M == "rock" and S == "rock"):
    print("F")
elif (M == "paper" and F == "rock" and S == "rock"):
    print("M")
elif (S == "paper" and F == "rock" and M == "rock"):
    print("S")
    
elif (F == "scissors" and M == "paper" and S == "paper"):
    print("F")
elif (M == "scissors" and F == "paper" and S == "paper"):
    print("M")
elif (S == "scissors" and F == "paper" and M == "paper"):
    print("S")        
else:
    print("?")    