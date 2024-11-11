N=int(input())+1
while len(set(str(N)))<4:
    N+=1
print(N)