m,n=map(int,input().split())

if(m>1):
    Width=n
    Height=m//2
    Extra=0

    if(m%2!=0):
        Extra=m//2

    NumberOfDominoes=Width*Height + Extra
else:
    NumberOfDominoes=n//2

print(NumberOfDominoes)