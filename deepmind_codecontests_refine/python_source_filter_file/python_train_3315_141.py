A,B=map(int,input().split(' '))
msg = 'Possible' if (A%3)*(B*3)*((A+B)%3)==0 else 'Impossible'
print(msg)