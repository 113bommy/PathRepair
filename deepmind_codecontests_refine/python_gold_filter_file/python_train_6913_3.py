k,d=map(int,input().split())

if(k==1):
    print(d)
elif(d!=0):
    print(10**(k-1)+d-1)
else:
    print("No solution")