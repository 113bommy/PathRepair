n=int(input())+1
for i in range(n,9050):
    if len(set(str(i))) ==4:
        print(i)
        break