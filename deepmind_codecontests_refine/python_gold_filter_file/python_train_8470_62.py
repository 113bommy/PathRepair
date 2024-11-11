n=int(input())+1
cond=True
while cond:
    year=str(n)
    if len(year)==len(set(year)):
        cond=False
        print(year)
    n+=1