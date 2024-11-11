n=int(input())
for i in range(1,11):
    n+=1
    if '8' in list(str(n)):
        print(i)
        exit()
        