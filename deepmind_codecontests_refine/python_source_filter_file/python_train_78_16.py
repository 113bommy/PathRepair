from string import ascii_lowercase

n = int(input())

def f(l):
    if len(l)==n:
        print("".join([ascii_lowercase[i] for i in l]))
        return
    
    for i in range(l[-1]+2):
        f(l+[i])

f([0])