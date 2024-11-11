n=input()
for x in range(10):
    n=int(n)
    n+=1
    n=str(n)
    if "8" in n:
        print(x+1)
        break
